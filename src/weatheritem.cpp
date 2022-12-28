#include "weatheritem.h"
#include "ui_weatheritem.h"

WeatherItem::WeatherItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherItem)
{
    ui->setupUi(this);

}

WeatherItem::~WeatherItem()
{
    delete ui;
}

void WeatherItem::setDate(const QString &newDate)
{
    ui->label_date->setText(newDate);
}

void WeatherItem::setTemp(const QString &newTemp)
{
    ui->label_temp->setText(newTemp);
}

void WeatherItem::setIcon(const QString &newIcon)
{
    QPixmap pix;
    if(newIcon == "Clear") {
        pix.load("://img/01.png");
    }
    else if(newIcon == "Clouds") {
        pix.load("://img/02.png");
    }
    else if(newIcon == "Rain") {
        pix.load("://img/10.png");
    }
    else if(newIcon == "Thunderstorm") {
        pix.load("://img/01.png");
    }
    else if(newIcon == "Drizzle") {
        pix.load("://img/03.png");
    }
    else if(newIcon == "Snow") {
        pix.load("://img/13.png");
    }
    else if(newIcon == "Atmosphere") {
        pix.load("://img/50.png");
    }


    ui->label_icon->setPixmap(pix);
}
