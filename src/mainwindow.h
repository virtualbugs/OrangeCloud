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
    int selected_day;

signals:
    void weatherInfoArrived();

public slots:
    void setData();
    void onTimeClicked(bool);
    void onDay0Clicked();
    void onDay1Clicked();
    void onDay2Clicked();
    void onDay3Clicked();
};
#endif // MAINWINDOW_H
