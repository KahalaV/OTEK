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

    void updateCoords(int dx, int dy);
    void setDirection(int dir);
    bool checkNewCoords(int dx, int dy);
    int getDir();
    int getSpeedStraight();
    int getSpeedDiagonal();
    int getBombRadius();

    const int quadrantSide_ = 24; //fourth of the image size

private:
    int dir_;
    int speedStraight_ = 4;
    int speedDiagonal_ = 3;
    int bombRadius = 50;
    QImage image_;
    Interface::Location loc_;
};

}

#endif // PLAYER_H
