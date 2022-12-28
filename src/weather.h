#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QXmlStreamReader>
#include <thread>
#include <unistd.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

// 3-hours forecast for 5 days


const double CELCIUS_TO_KELVIN = 273.15;


enum RequestType {
    GEO,
    WEATHER,
};

struct LocationInfo {
    QString city;
    QString country;
    QString state;
    QString lat;
    QString lon;
};

struct WeatherInfo {
    QString date_time;
    QString max_temp;
    QString min_temp;
    QString temp;
    QString humidity_percentage;
    QString wind_speed;
    QString cloudiness;
    QString weather_description;
    QString icon;
};

struct Date {
    QString year;
    QString month;
    QString day;
    QString hour;
};

enum Days {
    DAY1,
    DAY2,
    DAY3,
    DAY4,
    DAY5,
};

class Weather: public QObject
{
    Q_OBJECT
public:
    Weather();

    QNetworkRequest* request;
    QNetworkAccessManager* networkManager;
    QNetworkReply *reply;
    QUrl http_request_url;

    QString api_units;
    QString api_city;
    QString currentTemp;
    QString maxTemp;
    QString minTemp;
    QString city;
    QString icon;

    RequestType reqType;
    QVector<LocationInfo> locationInfos;
    LocationInfo selectedLocationInfo;
    QList<WeatherInfo> weatherInfos;

public slots:
    void replyFinished();
    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError error);
    void slotSslErrors();
    QString getCurrentTemp();
    QString getCity();
    QString getIcon();

private:
    static const QString API_key;
    void httpRequest(RequestType );

signals:
    void weatherInfoArrived();
};

#endif // WEATHER_H
