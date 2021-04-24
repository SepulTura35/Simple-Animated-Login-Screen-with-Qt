#include "mainwindow.h"
#include "MyTimer.h"
#include <QApplication>
#include <QGraphicsItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTimer mTimer;
    MainWindow w;
    w.show();
    return a.exec();
}

