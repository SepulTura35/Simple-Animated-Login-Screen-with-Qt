#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GraphicsMovieItem : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
public:
  GraphicsMovieItem(QGraphicsItem* parent = 0);
  void setMovie(QMovie* movie);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void frameChanged();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QMovie* m_movie;
};
#endif // MAINWINDOW_H
