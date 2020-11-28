#ifndef PLAYER_H
#define PLAYER_H

#include "core/location.hh"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>

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
    bool isRecentlyHit();
    void setHit(bool hitStatus);
    void addBombs();
    int getBombs();
    void dropBomb();
    void decreaseHealth();
    int getHealth();
    bool healthLeft();
    void setPlaneType(int plane);

private:
    int dir_;
    double bombs_;
    double bombsIncrease = 0.05;
    int speedStraight_;
    int speedDiagonal_;
    int bombRadius;
    bool recentlyHit_;
    QImage image_;
    int planeType_; // 1 = Red Baron, 2 = Bomber, 3 = Thunderbird
    int health_ = 4;
};

}

#endif // PLAYER_H
