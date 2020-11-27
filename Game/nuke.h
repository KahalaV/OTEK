#ifndef NUKE_H
#define NUKE_H

#include "bomb.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

namespace Student {

class Nuke : public QGraphicsItem
{
public:
    Nuke();
    ~Nuke();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool getStatus();
    int getDropTime();
    int getExplosionTime();
    void explode();
    void setDirection(int dir);
    QImage drawBomb();

private:
    int dropTime_;
    int explosionTime_;
    bool exploded_;
    QImage image_;
    int dir_;

};

}

#endif // NUKE_H
