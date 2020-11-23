#ifndef PLAYER_H
#define PLAYER_H

#include "core/location.hh"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

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

    const int quadrantSide_ = 24; //fourth of the image size

private:
    int dir_;
    int speedStraight_ = 4; //rb = 4; bm = 3; tb = 6
    int speedDiagonal_ = 3; //rb = 3; bm = 2; tb = 4
    int bombRadius = 40; //rb = 40; bm = 50; tb = 30
    QImage image_;
};

}

#endif // PLAYER_H
