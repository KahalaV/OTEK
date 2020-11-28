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

    int getType();
    void setType(int type);

private:
    QImage image_;
    int type_; //0 = passenger, 1 = nysse, 2 = destroyed nysse
};

}
#endif // ACTORITEM_H
