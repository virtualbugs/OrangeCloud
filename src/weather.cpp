#include "weather.h"

extern std::string openweather3parthlib;

Weather::Weather()
{
    city = "unknown";
    icon = "qrc:/img/01.png";
    api_units = "metric";
    api_city = "Madrid";
}

// Http Request from OpenWeatherMap.org
void Weather::startRequest(RequestType rType)
{
    if(rType == RequestType::GEO) {
        QString url = "http://api.openweathermap.org/geo/1.0/direct?q=London&limit=5&appid="
                +QString::fromStdString(openweather3parthlib);
         http_request_url = url;
         reqType = RequestType::GEO;
    }
    else if(rType == RequestType::WEATHER) {
        /// TODO: edit  "lat":39.8864493,"lon":-83.448253,
        selectedLocationInfo.lat = "35";
        selectedLocationInfo.lon = "139";
        QString url="https://api.openweathermap.org/data/2.5/forecast?lat=35&lon=139&appid="+ QString::fromStdString(openweather3parthlib);
        http_request_url = url;
        reqType = RequestType::WEATHER;
    }

    request = new QNetworkRequest(http_request_url);
    networkManager = new QNetworkAccessManager(this);
    weatherDataReply = networkManager->get(*request);

    connect(networkManager, &QNetworkAccessManager::finished,
            this, &Weather::onWeatherDataFetchingCompleted);
    connect(weatherDataReply, &QIODevice::readyRead,
            this, &Weather::onWeatherDataArrived);
    connect(weatherDataReply, &QNetworkReply::errorOccurred,
            this, &Weather::onNetworkReplyError);
    connect(weatherDataReply, &QNetworkReply::sslErrors,
            this, &Weather::on_SSL_Error);
}

void Weather::insertWeatherInfo(WeatherInfo data)
{
    /*** get the Day and Hour of the date ***/
    // 0- date format : "2023-01-04 12:00:00"
    QString date = data.date_time;
    // 1- split with space, take first argument
    QStringList date_and_time = date.split(' ');
    QStringList time_h_m_s = date_and_time[1].split(':');   // hour-minute-second time format
    QString hour_string = date_and_time[1].split(':')[0];
    int hour = hour_string.toInt();
    // 2- split with '-' , take third argument
    QStringList date_y_m_d = date_and_time[0].split('-');   // year-month-day date format
    QString day = date_y_m_d[2];


    // check in which day we are ; Days::DAY1, Days::DAY2 ...etc
    static int today = day.toInt();
    static int theDay = 0;
    if(today != day.toInt()) {
        today = day.toInt();
        theDay++;
    }

    if(theDay > 3)
        return;

    // assign the data to proper place of array
    weatherInfos[theDay%4][hour/3] = data;
}


void Weather::onWeatherDataFetchingCompleted()
{
    qDebug() << "Weather Data Fetching Is Completed.";
}

void Weather::onWeatherDataArrived()
{
    const QByteArray data = weatherDataReply->readAll();

    if(reqType == RequestType::GEO) {
        QJsonDocument document = QJsonDocument::fromJson(data);
        QJsonArray jsonArray = document.array();
        for(auto it=jsonArray.begin(); it != jsonArray.end(); ++it) {

            QJsonValue val = *it;
            QJsonObject obj = val.toObject();

            LocationInfo locationInfo;
            locationInfo.city = obj.value("name").toString();
            locationInfo.country = obj.value("country").toString();
            locationInfo.lat = obj.value("lat").toString();
            locationInfo.lon = obj.value("lon").toString();
            locationInfo.state = obj.value("state").toString();

            locationInfos.push_back(locationInfo);
        }
    }

    else if(reqType == RequestType::WEATHER) {
        QJsonDocument document = QJsonDocument::fromJson(data);
        QJsonObject obj = document.object();
        QJsonArray jarr = obj.value("list").toArray();
        WeatherInfo weather_info;
        int debug_item_i=0;


        for(auto i_time=jarr.begin(); i_time != jarr.end(); ++i_time) {
            QJsonValue val = *i_time;
            QJsonObject obj = val.toObject();



            weather_info.date_time = obj.value("dt_txt").toString();
            weather_info.max_temp = QString::number(obj.value("main").toObject().value("temp_max").toDouble() - CELCIUS_TO_KELVIN);
            weather_info.min_temp = QString::number(obj.value("main").toObject().value("temp_min").toDouble() - CELCIUS_TO_KELVIN);
            weather_info.temp = QString::number(obj.value("main").toObject().value("temp").toDouble() - CELCIUS_TO_KELVIN);
            weather_info.humidity_percentage = QString::number(obj.value("main").toObject().value("humidity").toInt());
            weather_info.wind_speed = QString::number(obj.value("wind").toObject().value("speed").toDouble());
            weather_info.cloudiness = QString::number(obj.value("clouds").toObject().value("all").toDouble());
            {
                QJsonValue val_inside_weather = *(obj.value("weather").toArray().begin());
                weather_info.weather_description = val_inside_weather.toObject().value("description").toString();
                weather_info.icon = val_inside_weather.toObject().value("main").toString();
            }


            qDebug() << "~~~~~" << "item-" << debug_item_i <<  "~~~~~" << "\n"
                            << "date : " << weather_info.date_time << "\n"
                            << "max temp : " << weather_info.max_temp << "\n"
                            << "min temp : " << weather_info.min_temp << "\n"
                            << "temp : " << weather_info.temp << "\n"
                            << "humidity percentage : " << weather_info.humidity_percentage << "\n"
                            << "wind speed : " << weather_info.wind_speed << "\n"
                            << "cloudiness : " << weather_info.cloudiness << "\n"
                            << "weather description : " << weather_info.weather_description << "\n"
                            << "icon : " << weather_info.icon << "\n";
            debug_item_i++;

            insertWeatherInfo(weather_info);
         }
    }
    emit weatherDataReady();
}

void Weather::onNetworkReplyError(QNetworkReply::NetworkError error)
{
    qDebug() << "Weather::onNetworkReplyError() : Network Reply Error, error code : " << error;
}

void Weather::on_SSL_Error()
{
    qDebug() << "Weather::on_SSL_Error() : SSL Error";
}


QString Weather::getCity()
{
    return city;
}

QString Weather::getIcon()
{
    return icon;
}
