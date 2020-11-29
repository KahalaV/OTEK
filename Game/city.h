#ifndef CITY_H
#define CITY_H

#include "interfaces/iactor.hh"
#include "interfaces/istop.hh"
#include "interfaces/icity.hh"
#include "actors/passenger.hh"
#include "mainwindow.h"
#include "endwindow.h"
#include "player.h"

#include <QObject>
#include <QTime>
#include <QTimer>
#include <iostream>
#include <QDebug>

/**
 *@file
 *@brief
 */

namespace Student
{

/**
 * @brief The City class controls the actions of the actors and acts as a link between logic and mainwindow
 */
class City : public Interface::ICity
{
public:

    /**
     * @brief City creates a new city
     * @param GAME_TIME defines how many seconds game round will last at maximum
     */
    City(const int GAME_TIME = 60);

    /**
     * @brief destructor
     */
    ~City();

    /**
     * @brief not used
     */
    void setBackground(QImage& basicbackground, QImage& bigbackground);

    /**
     * @brief sets the in-game city time to a new time
     * @param new time
     */
    void setClock(QTime clock);

    /**
     * @brief Takes coordinates from the new stop and sends them to MainWindow to draw a stop
     * @param stop to be added
     */
    void addStop(std::shared_ptr<Interface::IStop> stop);

    /**
     * @brief Starts the game round through MainWindow
     */
    void startGame();

    /**
     * @brief Checks if the game is over through MainWindow (time has run out or player's health has gone to 0)
     * @return true if game is over, false if not
     */
    bool isGameOver() const;

    /**
     * @brief Opens up the EndWindow
     */
    void endGame() const;

    //actors

    /**
     * @brief Adds new actor to the city if the actor is not a passenger
     * @param actor to be added
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor);

    /**
     * @brief Removes an actor from the city
     * @param actor to be removed
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief not used
     */
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief Checks if a certain actor is in the city
     * @param actor to be checked
     * @return
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    /**
     * @brief Updates the actor position
     * @param actor to be moved
     */
    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief not used
     */
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const;

    //player

    /**
     * @brief Creates a new player object and adds it to the city
     */
    void setPlayer();

    /**
     * @brief Sets the name of the player
     * @param Player name
     */
    void setPlayerName(QString &name);

    /**
     * @brief Sets the plane type of the player (1, 2 or 3)
     * @param number repesenting the plane type
     */
    void setPlaneType(int &plane);

private:
    QTime clock_;
    std::shared_ptr<Student::MainWindow> mainWindow_;
    bool gamestatus_ = false;
    Student::Player* player_;
    QString playerName_;
    int planeType_;
    const int gameTime_;
};

}

#endif // CITY_H
