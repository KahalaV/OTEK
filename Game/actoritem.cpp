#include "actoritem.h"

namespace Student {

ActorItem::ActorItem(int x, int y, int type):type_(type)
{
    setPos(mapToParent(x, y));
    if (type_ == 0) {
        image_ = QImage(":/Resources/Graphics/passenger.bmp");
        setZValue(0.3);
    }
    if (type_ == 1) {
         image_ = QImage(":/Resources/Graphics/nysse.bmp");
         setZValue(0.6);
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
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
int ActorItem::getType()
{
    return type_;
}
void ActorItem::setType(int type)
{
    type_ = type;
    if (type == 2) {
         image_ = QImage(":/Resources/Graphics/destroyed_nysse.bmp");
         setZValue(0.2);
    }
}

}
