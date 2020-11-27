#include "player.h"

namespace Student {

Player::Player() :
    dir_(1),
    recentlyHit_(false),
    hasNuke_(false),
    bombs_(5)
{
    setPos(50, 520);
    setZValue(1);
    setTransformOriginPoint(this->boundingRect().center());
}

Player::~Player()
{

}

QRectF Player::boundingRect() const
{
    return QRectF(0, 0, 49, 49);
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
bool Player::isRecentlyHit()
{
    return recentlyHit_;
}
void Player::setHit(bool hitStatus)
{
    recentlyHit_ = hitStatus;
}
void Player::addBombs()
{
    bombs_ += bombsIncrease;
}
int Player::getBombs()
{
    return bombs_;
}
void Player::dropBomb()
{
    bombs_--;
}
void Player::decreaseHealth()
{
    health_--;
}
bool Player::healthLeft() {
    if (health_ <= 0) {
        return true;
    } else {
        return false;
    }
}

void Player::setPlaneType(int plane)
{
    planeType_ = plane;
    switch (plane)
    {
        case 2:
            image_ = QImage(":/Resources/Graphics/bomber.bmp");
            speedStraight_ = 3;
            speedDiagonal_ = 2;
            bombRadius = 50;
            // same
            break;
        case 3:
            image_ = QImage(":/Resources/Graphics/thunderbird.bmp");
            speedStraight_ = 6;
            speedDiagonal_ = 4;
            bombRadius = 30;
            break;
        default:
            image_ = QImage(":/Resources/Graphics/red_baron.bmp");
            speedStraight_ = 4;
            speedDiagonal_ = 3;
            bombRadius = 40;
    }
}

int Player::getHealth()
{
    return health_;
}
bool Player::hasNuke()
{
    return hasNuke_;
}
void Player::setNuke(bool status)
{
    hasNuke_ = status;
}

}
