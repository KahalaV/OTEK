#ifndef ACTORITEM_H
#define ACTORITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

namespace Student {

class ActorItem : public QGraphicsItem
{
public:
    ActorItem(int x, int y, int type);
    ~ActorItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setCoord(int x, int y);
    int returnX();
    int returnY();

private:
    int x_;
    int y_;
    int type_;
    QImage image_;
};

}
#endif // ACTORITEM_H
