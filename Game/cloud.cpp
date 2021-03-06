#include "cloud.h"

namespace Student {

Cloud::Cloud(int y) :
    image_(QImage(":/Resources/Graphics/cloud.bmp"))
{
    setX(1095);
    setY(y);
    setZValue(1.1);
}
Cloud::~Cloud()
{

}
QRectF Cloud::boundingRect() const
{
    return QRectF(0, 0, 41, 41);
}
void Cloud::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(QPoint(0, 0), image_);
}
int Cloud::getSpeed()
{
    return speed_;
}

}
