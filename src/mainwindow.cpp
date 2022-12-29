#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    weather = new Weather;

    day_1 = new WeatherItem();
    day_2 = new WeatherItem();
    day_3 = new WeatherItem();
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
    QString day1_temp = weather->weatherInfos.at(5).max_temp;
    QString day1_date = weather->weatherInfos.at(5).date_time;
    QString day1_icon = weather->weatherInfos.at(5).icon;

    day_1->setTemp(day1_temp);
    day_1->setDate(day1_date);
    day_1->setIcon(day1_icon);

    QString day2_temp = weather->weatherInfos.at(13).max_temp;
    QString day2_date = weather->weatherInfos.at(13).date_time;
    QString day2_icon = weather->weatherInfos.at(13).icon;

    day_2->setTemp(day2_temp);
    day_2->setDate(day2_date);
    day_2->setIcon(day2_icon);

    QString day3_temp = weather->weatherInfos.at(21).max_temp;
    QString day3_date = weather->weatherInfos.at(21).date_time;
    QString day3_icon = weather->weatherInfos.at(21).icon;

    day_3->setTemp(day3_temp);
    day_3->setDate(day3_date);
    day_3->setIcon(day3_icon);
}
