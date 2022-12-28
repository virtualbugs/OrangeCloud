#ifndef WEATHERITEM_H
#define WEATHERITEM_H

#include <QWidget>
#include <QImage>
#include <QNetworkAccessManager>


namespace Ui {
class WeatherItem;
}

class WeatherItem : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherItem(QWidget *parent = nullptr);
    ~WeatherItem();

    void setIcon(const QString &newIcon);
    void setTemp(const QString &newTemp);
    void setDate(const QString &newDate);

    QImage image;
    QNetworkAccessManager networkmanager;

private:
    Ui::WeatherItem *ui;
};

#endif // WEATHERITEM_H
