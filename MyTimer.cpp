#include "MyTimer.h"
#include <QtCore>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"

MyTimer::MyTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));
    timer->start(1000);
}

