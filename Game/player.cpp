#include "player.h"

namespace Student {

Player::Player() :
    dir_(1),
    image_(QImage(":/Resources/Graphics/plane_N.bmp"))
{
    setPos(600, 300);
    setZValue(1);
}

Player::~Player()
{

}

QRectF Player::boundingRect() const
{
    return QRectF(0, 0, 150, 150);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(QPoint(0, 0), image_);
    /* enable to show coordinates on map
    QString text(QString::number(this->x()) + " " + QString::number(this->y()));
    QPen pen2(QBrush(QColor(0,0,0)),2);
    painter->setPen(pen2);
    painter->drawText(10, 20, text); */
}
void Player::setDirection(int dir)
{
    if (dir == 1) {
        image_ = QImage(":/Resources/Graphics/plane_N.bmp");
        dir_ = dir;
    }
    if (dir == 2) {
        image_ = QImage(":/Resources/Graphics/plane_NE.bmp");
        dir_ = dir;
    }
    if (dir == 3) {
        image_ = QImage(":/Resources/Graphics/plane_E.bmp");
        dir_ = dir;
    }
    if (dir == 4) {
        image_ = QImage(":/Resources/Graphics/plane_SE.bmp");
        dir_ = dir;
    }
    if (dir == 5) {
        image_ = QImage(":/Resources/Graphics/plane_S.bmp");
        dir_ = dir;
    }
    if (dir == 6) {
        image_ = QImage(":/Resources/Graphics/plane_SW.bmp");
        dir_ = dir;
    }
    if (dir == 7) {
        image_ = QImage(":/Resources/Graphics/plane_W.bmp");
        dir_ = dir;
    }
    if (dir == 8) {
        image_ = QImage(":/Resources/Graphics/plane_NW.bmp");
        dir_ = dir;
    }
}
bool Player::checkNewCoords(int dx, int dy)
{
    int x = this->x();
    int y = this->y();
    if (x + dx < 0) {
        return true;
    }
    if (x + dx > 1040) {
        return true;
    }
    if (y + dy < 0) {
        return true;
    }
    if (y + dy > 540) {
        return true;
    }
    return false;
}
void Player::updateCoords(int dx, int dy)
{
    this->setX(this->x() + dx);
    this->setY(this->y() + dy);
}
int Player::getDir()
{
    return dir_;
}
int Player::getSpeedStraight()
{
    return speedStraight_;
}

int Player::getSpeedDiagonal()
{
    return speedDiagonal_;
}
int Player::getBombRadius()
{
    return bombRadius;
}

}
