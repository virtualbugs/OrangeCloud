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
    selected_day=0;

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

    connect(ui->time_00_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));
    connect(ui->time_03_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));
    connect(ui->time_06_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));
    connect(ui->time_09_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));
    connect(ui->time_12_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));
    connect(ui->time_15_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));
    connect(ui->time_18_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));
    connect(ui->time_21_00, SIGNAL(clicked(bool)),
            this, SLOT(onTimeClicked(bool)));

    connect(day_0, SIGNAL(dayClicked()),
            this, SLOT(onDay0Clicked()));
    connect(day_1, SIGNAL(dayClicked()),
            this, SLOT(onDay1Clicked()));
    connect(day_2, SIGNAL(dayClicked()),
            this, SLOT(onDay2Clicked()));
    connect(day_3, SIGNAL(dayClicked()),
            this, SLOT(onDay3Clicked()));
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

    day_0->setButtonStyle(QString("background-color: rgb(255, 255, 255);"
                                 "font: 16pt \"Sans Serif\";"
                                 "color: rgb(0, 85, 255);"));
    day_1->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_2->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_3->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");

    ui->selected_hour_temp->setText(weather->weatherInfos[0][7].temp);
    ui->selected_hour_humidity ->setText(weather->weatherInfos[0][7].humidity_percentage);
    ui->selected_hour_weather_info->setText(weather->weatherInfos[0][7].weather_description);
    ui->selected_hour_image->setText(weather->weatherInfos[0][7].icon);
    ui->selected_hour_wind->setText(weather->weatherInfos[0][7].wind_speed);
    ui->seleceted_hour_cloud->setText(weather->weatherInfos[0][7].cloudiness);
}

void MainWindow::onTimeClicked(bool)
{
    if(ui->time_00_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][0].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][0].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][0].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][0].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][0].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][0].cloudiness);
    }
    else if(ui->time_03_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][1].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][1].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][1].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][1].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][1].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][1].cloudiness);
    }
    else if(ui->time_06_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][2].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][2].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][2].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][2].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][2].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][2].cloudiness);
    }
    else if(ui->time_09_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][3].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][3].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][3].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][3].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][3].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][3].cloudiness);
    }
    else if(ui->time_12_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][4].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][4].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][4].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][4].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][4].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][4].cloudiness);
    }
    else if(ui->time_15_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][5].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][5].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][5].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][5].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][5].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][5].cloudiness);
    }
    else if(ui->time_18_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][6].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][6].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][6].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][6].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][6].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][6].cloudiness);
    }
    else if(ui->time_21_00->isChecked()) {
        ui->selected_hour_temp->setText(weather->weatherInfos[selected_day][7].temp);
        ui->selected_hour_humidity ->setText(weather->weatherInfos[selected_day][7].humidity_percentage);
        ui->selected_hour_weather_info->setText(weather->weatherInfos[selected_day][7].weather_description);
        ui->selected_hour_image->setText(weather->weatherInfos[selected_day][7].icon);
        ui->selected_hour_wind->setText(weather->weatherInfos[selected_day][7].wind_speed);
        ui->seleceted_hour_cloud->setText(weather->weatherInfos[selected_day][7].cloudiness);
    }
}

void MainWindow::onDay0Clicked()
{
    selected_day=0;


    day_0->setButtonStyle(QString("background-color: rgb(255, 255, 255);"
                                 "font: 16pt \"Sans Serif\";"
                                 "color: rgb(0, 85, 255);"));
    day_1->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_2->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_3->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
}

void MainWindow::onDay1Clicked()
{
    selected_day=1;

    day_1->setButtonStyle(QString("background-color: rgb(255, 255, 255);"
                                 "font: 16pt \"Sans Serif\";"
                                 "color: rgb(0, 85, 255);"));
    day_0->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_2->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_3->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
}

void MainWindow::onDay2Clicked()
{
    selected_day=2;

    day_2->setButtonStyle(QString("background-color: rgb(255, 255, 255);"
                                 "font: 16pt \"Sans Serif\";"
                                 "color: rgb(0, 85, 255);"));
    day_1->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_0->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_3->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
}

void MainWindow::onDay3Clicked()
{
    selected_day=3;

    day_3->setButtonStyle(QString("background-color: rgb(255, 255, 255);"
                                 "font: 16pt \"Sans Serif\";"
                                 "color: rgb(0, 85, 255);"));
    day_1->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_2->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
    day_0->setButtonStyle("background-color: rgb(0, 85, 255);"
                          "font: 16pt \"Sans Serif\";"
                          "color: rgb(228, 230, 235);");
}

