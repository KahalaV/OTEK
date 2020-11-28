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
    bool isExploded();
    int getDropTime();
    int getExplosionTime();
    void decreaseDropTime();
    void increaseExplosionTime();
    void explode();
    void setDirection(int dir);
    QImage drawBomb();
    void setStatus(int status);
    int getStatus();

private:
    QImage image_;
    int dir_;
    int status_; //0 = no nuke in game, 1 = on map to be collected, 2 = player has nuke, not dropped, 3 = dropping
    bool exploded_;
    int dropTime_;
    int explosionTime_;
};

}

#endif // NUKE_H
