#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>

/**
 *@file
 *@brief
 */

namespace Student {

class Player : public QGraphicsItem
{
public:

    /**
     * @brief Creates the player object
     */
    Player();

    /**
     * @brief Destructor
     */
    ~Player();

    /**
     * @brief boundingRect of the graphicsitem
     * @return returns boundingRect
     */
    QRectF boundingRect() const;

    /**
     * @brief Used to draw graphicsitems to graphicsscene
     * @param painter - required as default
     * @param option - required as default
     * @param widget - required as default
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief Sets new direction for the player: 1 = north, 2 = northeast, 3 = east etc.
     * @param new direction
     */
    void setDirection(int dir);

    /**
     * @brief Checks the new location of the player to prevent the player going over the limits of the game area
     * @param dx - change in x coord
     * @param dy - change in y coord
     * @return
     */
    bool checkNewCoords(int dx, int dy);

    /**
     * @brief Returns the direction of the player
     * @return
     */
    int getDir();

    /**
     * @brief Returns the vertical and horizonal speed of the player (pixels per tick)
     * @return
     */
    int getSpeedStraight();

    /**
     * @brief Returns the diagonal speed of the player (pixels per tick)
     * @return
     */
    int getSpeedDiagonal();

    /**
     * @brief Returns the bomb destruction radius of the bombs of the player's plane
     * @return
     */
    int getBombRadius();

    /**
     * @brief Increase the amount of the player's available bombs by a fixed amount
     */
    void addBombs();

    /**
     * @brief Returns the current number of usable bombs the player has (decimals rounded off)
     * @return
     */
    int getBombs();

    /**
     * @brief Decrease amount of bombs by 1
     */
    void dropBomb();

    /**
     * @brief Decrease the health of the player by 1
     */
    void decreaseHealth();

    /**
     * @brief Return current health of player
     * @return
     */
    int getHealth();

    /**
     * @brief Return true if player's health > 0, false if no health left
     * @return
     */
    bool healthLeft();

    /**
     * @brief Set the type of the player's plane
     * @param plane type
     */
    void setPlaneType(int plane);

    /**
     * @brief Decrease the remaining cooldown after colliding with a cloud by 1
     */
    void decreaseCooldown();

    /**
     * @brief Sets the cooldown of the player
     * @param new cooldown
     */
    void setCooldown(int newCooldown);

    /**
     * @brief Returns the current cooldown of the player
     * @return
     */
    int getCooldown();

    /**
     * @brief Returns the static cooldown that the players cooldown is set to after colliding with a cloud
     * @return
     */
    int getCoolDownDuration();

private:
    QImage image_;
    int dir_;
    int planeType_; // 1 = Red Baron, 2 = Bomber, 3 = Thunderbird
    int speedStraight_;
    int speedDiagonal_;
    double bombs_;
    double bombsIncrease = 0.02;
    int health_;
    int bombRadius_;
    int cloudHitCooldown_;
    int coolDownDuration_;
};

}

#endif // PLAYER_H
