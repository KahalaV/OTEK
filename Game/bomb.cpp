#include "bomb.h"

namespace Student {

Bomb::Bomb() :
    exploded_(false),
    image_(QImage(":/Resources/Graphics/bomb.bmp")),
    dropTime_(10),
    explosionTime_(0)
{
    setZValue(0.9);
    setTransformOriginPoint(this->boundingRect().center());
}

Bomb::~Bomb()
{

}

QRectF Bomb::boundingRect() const
{
    return QRectF(0, 0, 49, 49);
}

void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(QPoint(0, 0), image_);
}

void Bomb::explode() {
    exploded_ = true;
    image_ = QImage(":/Resources/Graphics/explosion.bmp");
}

bool Bomb::getStatus() {
    return exploded_;
}

void Bomb::setDirection(int dir)
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

int Bomb::getDropTime()
{
    return dropTime_;
}
int Bomb::getExplosionTime() {
    return explosionTime_;
}

}
