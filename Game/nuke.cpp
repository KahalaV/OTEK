#include "nuke.h"
#include <QDebug>
namespace Student {

Nuke::Nuke() :
    exploded_(false),
    status_(0),
    dropTime_(10),
    explosionTime_(0),
    dir_(1),
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
    return QRectF(0, 0, 43, 43);
}

void Nuke::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(QPoint(0, 0), image_);
}
void Nuke::setDirection(int dir)
{
    if (dir == 1) {
        this->setRotation(0);
        dir_ = dir;
    }
    if (dir == 2) {
        this->setRotation(45);
        dir_ = dir;
    }
    if (dir == 3) {
        this->setRotation(90);
        dir_ = dir;
    }
    if (dir == 4) {
        this->setRotation(135);
        dir_ = dir;
    }
    if (dir == 5) {
        this->setRotation(180);
        dir_ = dir;
    }
    if (dir == 6) {
        this->setRotation(225);
        dir_ = dir;
    }
    if (dir == 7) {
        this->setRotation(270);
        dir_ = dir;
    }
    if (dir == 8) {
        this->setRotation(315);
        dir_ = dir;
    }
}
void Nuke::explode() {
    exploded_ = true;
    qDebug() << "set image to explosion";
    image_ = QImage(":/Resources/Graphics/explosion.bmp");
}

bool Nuke::isExploded() {
    return exploded_;
}
void Nuke::setStatus(int status)
{
    status_ = status;
    if (status == 0) {
        //set image back to bomb and normal size after explosion
        setScale(1);
        setDirection(1);
        dropTime_ = 10;
        explosionTime_ = 0;
        exploded_ = false;
        image_ = (QImage(":/Resources/Graphics/nuke.bmp"));
    }
    qDebug() << "nuke status set to " << status;
}
int Nuke::getStatus()
{
    return status_;
}

}
