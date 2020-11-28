#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "actoritem.h"
#include "cloud.h"
#include "interfaces/istop.hh"
#include "interfaces/iactor.hh"
#include "actors/passenger.hh"
#include "player.h"
#include <iostream>
#include "bomb.h"
#include "nuke.h"
#include "statistics.hh"

#include "cstdlib"
#include "QSound"
#include "unistd.h"
#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <memory>
#include <QDebug>
#include <QDesktopWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMainWindow>
#include <QScreen>
#include <QSound>
#include <QTime>
#include <QTimer>
#include <QVector>

/**
 *@file
 *@brief
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
    void startGame(const int GAME_TIME);
    bool isGameOver();
    void dropBomb();
    void setPlayerName(QString &name);
    void dropNuke();
    void updateNuke();
    void setPlayer(Student::Player* player);
    void keyPressEvent(QKeyEvent *event);
    void movePlayer();
    void addClouds();
    void moveClouds();
    void decreaseGameTime();
    std::vector<int> randomizeCloudSlots();
    void spawnNuke();
    void updateBombs();


public slots:
    void update();

private:
    Ui::MainWindow* ui;
    std::shared_ptr<Student::Statistics> statistics_;
    QGraphicsScene* map;
    QTimer* timer;
    QTime timeLeft_;
    QTime* clock_;
    QVector<std::pair<std::shared_ptr<Interface::IActor>, Student::ActorItem*>> actors_;
    QVector<Student::Cloud*> clouds_;
    QVector<Student::Bomb*> bombs_;
    Student::Player* player_;
    QString playerName_;
    Student::Nuke* nuke_;
    int score_;
    int cloudStatus_;
    bool gameOver;
    double tick_ = 50; //ms per game tick
    int cloudInterval_ = 50; //ticks between cloud sets
    const int width_ = 1095;
    const int height_ = 592;
};

}

#endif // MAINWINDOW_H
