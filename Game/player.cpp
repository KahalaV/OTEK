#include "player.h"

namespace Student {

Player::Player() :
    x_(600),
    y_(300),
    dir_(1),
    image_(QImage(":/Resources/Graphics/plane_N.bmp"))
{
    setPos(x_, y_);
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
    if (x_ + dx < 0) {
        return true;
    }
    if (x_ + dx > 1040) {
        return true;
    }
    if (y_ + dy < 0) {
        return true;
    }
    if (y_ + dy > 540) {
        return true;
    }
    return false;
}
void Player::updateCoords(int dx, int dy)
{
    x_ += dx;
    y_ += dy;
}
}
