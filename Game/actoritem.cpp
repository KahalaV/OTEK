#include "actoritem.h"

namespace Student {

ActorItem::ActorItem(int x, int y, int type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
}

ActorItem::~ActorItem()
{

}

QRectF ActorItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void ActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (type_ == 0)
    {
        painter->drawImage(QPoint(0, 0), QImage(":/Resources/Graphics/passenger.bmp"));
    }
    if (type_ == 1) {
        painter->drawImage(QPoint(0, 0), QImage(":/Resources/Graphics/nysse.bmp"));
    }
}

void ActorItem::setCoord(int x, int y)
{
    setX(x);
    setY(y);
}

}
