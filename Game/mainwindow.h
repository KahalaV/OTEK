#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "actoritem.h"
#include "cloud.h"
#include "interfaces/istop.hh"
#include "interfaces/iactor.hh"
#include "actors/passenger.hh"
#include "player.h"
#include <iostream>

#include <QKeyEvent>
#include <QDebug>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include <math.h>
#include "cstdlib"
#include "QSound"
#include <bits/stdc++.h>
#include <iterator>
#include <QGraphicsRectItem>


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
    void addActor(std::shared_ptr<Interface::IActor> newactor);
    void removeActor(std::shared_ptr<Interface::IActor> actor);
    bool findActor(std::shared_ptr<Interface::IActor> actor);
    void addStop(int x, int y);
    void moveActor(std::shared_ptr<Interface::IActor> actor);
    void updateTimeLabel();

    //player
    void setPlayer(Student::Player* player);
    void keyPressEvent(QKeyEvent *event);
    void dropBomb();

    //clouds
    void addClouds();
    std::vector<int> randomizeCloudSlots();


public slots:
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
    QVector<std::pair<std::shared_ptr<Interface::IActor>, Student::ActorItem*>> actors_;
    QVector<Student::Cloud*> clouds_;
    Student::Player* player_;
    int score_;
    int cloudStatus_;

    int tick_ = 50;
    int cloudInterval_ = 50; //ticks between cloud sets
    int width_ = 1095;
    int height_ = 592;
};

}

#endif // MAINWINDOW_H
