#include "src/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setFixedSize(200,400);
    w.show();
    return a.exec();
}
