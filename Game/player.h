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
    Player();
    ~Player();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setDirection(int dir);
    bool checkNewCoords(int dx, int dy);
    int getDir();
    int getSpeedStraight();
    int getSpeedDiagonal();
    int getBombRadius();
    void addBombs();
    int getBombs();
    void dropBomb();
    void decreaseHealth();
    int getHealth();
    bool healthLeft();
    void setPlaneType(int plane);
    void decreaseCloudHitCooldown();
    void setCooldown(int newCooldown);
    int getCooldown();
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
    int bombRadius;
    int cloudHitCooldown_;
    int coolDownDuration_;
};

}

#endif // PLAYER_H
