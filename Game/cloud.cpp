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
    painter->drawImage(QPoint(0, 0), image_);
    /* enable to show coordinates on map
    QString text(QString::number(this->x()) + " " + QString::number(this->y()));
    QPen pen2(QBrush(QColor(0,0,0)),2);
    painter->setPen(pen2);
    painter->drawText(10, 20, text); */
}
int Cloud::getSpeed()
{
    return speed_;
}

}
