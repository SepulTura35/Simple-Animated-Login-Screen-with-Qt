#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSizePolicy>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QMovie>
#include <QTimer>
#include "MyTimer.h"
#include "customshadoweffect.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground,true);

    ui->logo->setVisible(false);


    //custom shader effect
    CustomShadowEffect *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(20.0);
    bodyShadow->setDistance(6.0);
    bodyShadow->setColor(QColor(0, 0, 0, 80));
    ui->giriswidget->setAutoFillBackground(true);
    ui->giriswidget->setGraphicsEffect(bodyShadow);


    //gif ekleme;
    QMovie *movie = new QMovie(":/new/prefix1/img/loading.gif");
    ui->loading->setMovie (movie);
    movie->start ();

    //animasyon;
    QPropertyAnimation *labelprogress = new QPropertyAnimation(ui->labelchunk, "geometry");
    labelprogress->setDuration(3500);
    labelprogress->setStartValue(QRect(20,250,21,21));
    labelprogress->setEndValue(QRect(20,250,241,21));
    labelprogress->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->logo->setVisible(true);

    QGraphicsOpacityEffect *iki = new QGraphicsOpacityEffect();
    ui->progresslabel->setGraphicsEffect(iki);
    QPropertyAnimation *ikinci = new QPropertyAnimation(iki,"opacity");
    ikinci->setDuration(500);
    ikinci->setStartValue(1.0);
    ikinci->setEndValue(0.0);
    ikinci->setEasingCurve(QEasingCurve::OutQuad);
    ikinci->start(QAbstractAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *uc = new QGraphicsOpacityEffect();
    ui->labelchunk->setGraphicsEffect(uc);
    QPropertyAnimation *ucuncu = new QPropertyAnimation(uc,"opacity");
    ucuncu->setDuration(500);
    ucuncu->setStartValue(1.0);
    ucuncu->setEndValue(0.0);
    ucuncu->setEasingCurve(QEasingCurve::OutQuad);
    ucuncu->start(QAbstractAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *ilk = new QGraphicsOpacityEffect();
    ui->loading->setGraphicsEffect(ilk);
    QPropertyAnimation *ilkan = new QPropertyAnimation(ilk,"opacity");
    ilkan->setDuration(500);
    ilkan->setStartValue(1.0);
    ilkan->setEndValue(0.0);
    ilkan->setEasingCurve(QEasingCurve::OutQuad);
    ilkan->start(QAbstractAnimation::DeleteWhenStopped);


    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect();
    ui->logo->setGraphicsEffect(effect);
    QPropertyAnimation *anim = new QPropertyAnimation(effect,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->setEasingCurve(QEasingCurve::OutQuad);
    anim->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation = new QPropertyAnimation(ui->giriswidget, "geometry");
    animation->setDuration(400);
    animation->setStartValue(QRect(10,80,281,301));
    animation->setEndValue(QRect(10,10,281,461));
    animation->start();

    QPropertyAnimation *logo = new QPropertyAnimation(ui->logo, "geometry");
    logo->setDuration(400);
    logo->setStartValue(QRect(20,110,261,131));
    logo->setEndValue(QRect(20,40,261,131));
    logo->start();

    QPropertyAnimation *loginanim = new QPropertyAnimation(ui->login, "geometry");
    loginanim->setDuration(400);
    loginanim->setStartValue(QRect(20,90,41,41));
    loginanim->setEndValue(QRect(20,20,41,41));
    loginanim->start();

    QPropertyAnimation *closeanim = new QPropertyAnimation(ui->close, "geometry");
    closeanim->setDuration(400);
    closeanim->setStartValue(QRect(240,90,41,41));
    closeanim->setEndValue(QRect(240,20,41,41));
    closeanim->start();
}



