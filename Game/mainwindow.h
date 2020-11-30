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
#include "statistics.h"

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


/**
 * @brief MainWindow acts as the interface between player and the game events
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~MainWindow();

    //initializing

    /**
     * @brief Sets the background image of the graphics scene
     * @param background image
     */
    void setPicture(QImage img);

    /**
     * @brief Sets the in-game clock
     * @param clock
     */
    void setClock(QTime &clock);

    /**
     * @brief Starts a new game round with a set amount of game time
     * @param game time in seconds
     */
    void startGame(const int GAME_TIME);

    /**
     * @brief Displays the player name on the MainWindow
     * @param player name
     */
    void setPlayerName(QString &name);

    /**
     * @brief Adds stop graphic to the graphics scene
     * @param x coordinate of the stop
     * @param y coordinate of the stop
     */
    void addStop(int x, int y);

    /**
     * @brief Sets the pointer to a player and adds the player graphic to the graphics scene
     * @param Pointer to the player
     */
    void setPlayer(Student::Player* player);

    //actors

    /**
     * @brief Creates a new ActorItem, pairs it with a logic actor and adds actor graphic to the graphics scene
     * @param Pointer to the new actor
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor);

    /**
     * @brief Removes the actor pair from the actors_ vector and removes the actors graphics from the graphics scene
     * @param Pointer to the actor to be removed
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief Checks if a certain actor is in the actors_ vector
     * @param Pointer to the actor to be checked
     * @return true if the actor is in the vector, false if not
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief Updates the coordinates of the actor and the actor graphics
     * @param Pointer to the actor to be moved
     */
    void moveActor(std::shared_ptr<Interface::IActor> actor);

    //spawning

    /**
     * @brief Returns an integer vector of size 12. The vector contains 1:s and 0:s. Indexes of the vector represent
     * horizontal tracks on the graphics scene. Indexes with 1 mean that a cloud will be spawned on that track.
     * @return
     */
    std::vector<int> randomizeCloudSlots();

    /**
     * @brief Randomizes cloud spawning locations using randomizeCloudSlots() function and adds the new clouds to the game.
     */
    void addClouds();

    /**
     * @brief Spawns a collectible nuke to the graphics scene in a random location and sets the nuke status to 1.
     */
    void spawnNuke();

    //player controls

    /**
     * @brief Registers key pressing events of the player and calls the appropriate functions
     * @param
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief Used to prevent scrolling the graphics scene with mousewheel
     * @param
     * @param
     * @return
     */

    bool eventFilter(QObject *object, QEvent *event);

    /**
     * @brief If the player has bombs left, creates a new bomb object and adds the bomb graphics to the graphics scene.
     */
    void dropBomb();

    /**
     * @brief setPlaneType
     * @param plane
     */
    void setPlaneType(int &plane);

    /**
     * @brief setStatistics
     */
    void setStatistics();

    /**
     * @brief If the player has a nuke, sets the nuke status to 3 and adds the dropping nuke graphics to the graphics scene.
     */
    void dropNuke();

    //update every game tick

    /**
     * @brief Moves the player a distance depending on the speed variables of the plane to the current direction of the player.
     */
    void movePlayer();

    /**
     * @brief Moves the clouds on the graphics scene to the left by a fixed amount.
     */
    void moveClouds();

    /**
     * @brief Updates the dropping/exploding nuke to the next stage on dropping/exploding. Checks the destroyed buses when
     * the nuke explodes.
     */
    void updateNuke();

    /**
     * @brief Updates the dropping/exploding bombs to the next stage on dropping/exploding. Checks the destroyed buses when
     * a bomb explodes.
     */
    void updateBombs();

    /**
     * @brief checks if there are actors in the explosion area and adds points to the player for actors destroyed
     */
    void checkExplosionHits(int x, int y, int radius);

    /**
     * @brief Updates the in-game clock label
     */
    void updateTimeLabel();

    /**
     * @brief Decreases the game time that the player has left and updates the time left label. If the game time runs out, sets
     * the gameOver_ variable to true.
     */
    void decreaseGameTime();

    //ending the game

    /**
     * @brief Returns true if gameOver_ has been set to true (time runs out or player health is 0). Returns
     * false if gameOver_ == false.
     * @return
     */
    bool isGameOver();

public slots:
    void update();

private:
    Ui::MainWindow* ui;
    std::shared_ptr<Student::Statistics> statistics_;
    QGraphicsScene* map;
    QGraphicsScene* nukeStatus;
    QTimer* timer;
    QTime timeLeft_;
    QTime* clock_;
    QVector<std::pair<std::shared_ptr<Interface::IActor>, Student::ActorItem*>> actors_;
    QVector<Student::Cloud*> clouds_;
    QVector<Student::Bomb*> bombs_;
    Student::Player* player_;
    QString playerName_;
    Student::Nuke* nuke_;
    int gameTime_;
    int score_;
    int nyssesDestroyed_;
    int cloudCollisions_;
    int bombsDropped_;
    int nukesDropped_;
    int planeType_;
    int cloudStatus_;
    bool gameOver_;
    const double tick_ = 50; //ms per game tick
    const int cloudInterval_ = 50; //ticks between cloud sets
    const int width_ = 1095;
    const int height_ = 592;
};

}

#endif // MAINWINDOW_H
