#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Orange Cloud Weather App");
    weather = new Weather;
    weather->startRequest();

    day_0 = new WeatherItem();
    day_1 = new WeatherItem();
    day_2 = new WeatherItem();
    day_3 = new WeatherItem();
    ui->vlayout_today->addWidget(day_0);
    ui->day1_vlayout->addWidget(day_1);
    ui->day2_vlayout->addWidget(day_2);
    ui->day3_vlayout->addWidget(day_3);


    connect(weather, SIGNAL(weatherDataReady()),
            this, SLOT(setData()));
}

MainWindow::~MainWindow()
{
    delete weather;
}

void MainWindow::setData()
{
    day_0->setDate("Today");
    day_1->setDate("Tomorrow");
    day_2->setDate(weather->weatherInfos[2][0].date_time.split(' ')[0]);
    day_3->setDate(weather->weatherInfos[3][0].date_time.split(' ')[0]);

    day_0->setTemp(weather->weatherInfos[0][7].temp);
    day_1->setTemp(weather->weatherInfos[1][4].temp);
    day_2->setTemp(weather->weatherInfos[2][4].temp);
    day_3->setTemp(weather->weatherInfos[3][4].temp);

    day_0->setIcon(weather->weatherInfos[0][7].icon);
    day_1->setIcon(weather->weatherInfos[1][4].icon);
    day_2->setIcon(weather->weatherInfos[2][4].icon);
    day_3->setIcon(weather->weatherInfos[3][4].icon);

    ui->selected_hour_temp->setText(weather->weatherInfos[0][7].temp);
    ui->selected_hour_humidity ->setText(weather->weatherInfos[0][7].humidity_percentage);
    ui->selected_hour_weather_info->setText(weather->weatherInfos[0][7].weather_description);
    ui->selected_hour_image->setText(weather->weatherInfos[0][7].icon);
    ui->selected_hour_wind->setText(weather->weatherInfos[0][7].wind_speed);
    ui->seleceted_hour_cloud->setText(weather->weatherInfos[0][7].cloudiness);
}
