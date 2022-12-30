#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "weather.h"
#include "weatheritem.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    Weather* weather;
    WeatherItem *day_0;
    WeatherItem *day_1;
    WeatherItem *day_2;
    WeatherItem *day_3;

signals:
    void weatherInfoArrived();

public slots:
    void setData();
};
#endif // MAINWINDOW_H
