#include "nuke.h"

namespace Student {

Nuke::Nuke() :
    exploded_(false),
    dropTime_(10),
    explosionTime_(0),
    image_(QImage(":/Resources/Graphics/nuke.bmp"))
{
    setZValue(0.9);
    setTransformOriginPoint(this->boundingRect().center());
}

Nuke::~Nuke()
{

}

QRectF Nuke::boundingRect() const
{
    return QRectF(0, 0, 43, 25);
}

void Nuke::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(QPoint(0, 0), image_);
}

}
