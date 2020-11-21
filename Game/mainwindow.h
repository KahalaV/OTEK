#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "actoritem.h"
#include "interfaces/istop.hh"
#include "interfaces/iactor.hh"
#include "player.h"
#include <iostream>

#include <QKeyEvent>
#include <QDebug>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTime>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include <math.h>

/*!
 * Doxytest start
 */

namespace Ui {
class MainWindow;
}

namespace Student {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPicture(QImage img);
    void setClock(QTime &clock);
    void addActor(int x, int y, int type);
    void addStop(int x, int y);
    void moveActor(ActorItem *actor, int x, int y);
    Student::ActorItem* returnActorItem(int index);

    //player
    void setPlayer(Student::Player* player);
    void keyPressEvent(QKeyEvent *event);
    void dropBomb();

public slots:
    void updateTimeLabel();
    //player
    void movePlayer();

public:

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer* timer;
    QTime* clock_;
    QVector<Student::ActorItem*> actors_;
    Student::Player* player_;

    int tick_ = 250;
    int width_ = 1095;
    int height_ = 592;
};

}

#endif // MAINWINDOW_H
