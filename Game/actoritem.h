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
    int getType();
    void setType(int type);

private:
    //0 = passenger, 1 = nysse, 2 = destroyed nysse
    int type_;
    QImage image_;
};

}
#endif // ACTORITEM_H
