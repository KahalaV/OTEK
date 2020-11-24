#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

namespace Student {

class Bomb : public QGraphicsPixmapItem
{
public:
    Bomb();
    ~Bomb();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool getStatus();
    int getDropTime();
    int getExplosionTime();
    void explode();
    void setDirection(int dir);
    QPixmap drawBomb();

    int dropTime_;
    int explosionTime_;

private:
    bool exploded_;
    QPixmap image_;
    int dir_;
};

}

#endif // BOMB_H
