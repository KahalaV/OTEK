#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "actoritem.h"
#include "cloud.h"
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
#include <vector>
#include <map>
#include <math.h>
#include "cstdlib"

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

    //clouds
    void addClouds();
    std::vector<int> randomizeCloudSlots();


public slots:
    void updateTimeLabel();
    //player
    void movePlayer();
    //clouds
    void moveClouds();

public:

private:
    Ui::MainWindow* ui;
    QGraphicsScene* map;
    QTimer* timer;
    QTime* clock_;
    QVector<Student::ActorItem*> actors_;
    QVector<Student::Cloud*> clouds_;
    Student::Player* player_;
    int score_;
    int cloudStatus_;

    int tick_ = 100;
    int cloudInterval_ = 50; //ticks between cloud sets
    int width_ = 1095;
    int height_ = 592;
};

}

#endif // MAINWINDOW_H
