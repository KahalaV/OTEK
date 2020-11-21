#ifndef PLAYER_H
#define PLAYER_H

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

    const int quadrantSide_ = 24;

private:
    int x_;
    int y_;
    int dir_;
    QImage image_;
};

}

#endif // PLAYER_H
