#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

namespace Student {

class Bomb : public QGraphicsItem
{
public:
    Bomb();
    ~Bomb();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool isExploded();
    int getDropTime();
    int getExplosionTime();
    void decreaseDropTime();
    void increaseExplosionTime();
    void explode();
    void setDirection(int dir);
    QImage getImage();

private:
    QImage image_;
    int dir_;
    int dropTime_;
    int explosionTime_;
    bool exploded_;
};

}

#endif // BOMB_H
