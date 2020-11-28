#ifndef CLOUD_H
#define CLOUD_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

namespace Student {

class Cloud : public QGraphicsItem
{
public:
    Cloud(int y);
    ~Cloud();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getSpeed();

private:
    QImage image_;
    int speed_ = 3; //pxls per tick
};

}

#endif // CLOUD_H
