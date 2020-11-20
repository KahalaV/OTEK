#include "actoritem.h"

namespace Student {

ActorItem::ActorItem(int x, int y, int type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
    if (type_ == 0) {
        image_ = QImage(":/Resources/Graphics/passenger.bmp");
        setZValue(0.6);
    }
    if (type_ == 1) {
         image_ = QImage(":/Resources/Graphics/nysse.bmp");
         setZValue(0.3);
    }
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
    painter->drawImage(QPoint(0, 0), image_);
}

void ActorItem::setCoord(int x, int y)
{
    setX(x);
    setY(y);
}

int ActorItem::returnX()
{
    return x_;
}

int ActorItem::returnY()
{
    return y_;
}

}
