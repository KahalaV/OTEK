#ifndef CLOUD_H
#define CLOUD_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

/**
 *@file
 *@brief
 */

namespace Student {

/**
 * @brief The Cloud class defines the clouds that move through the map fro right to left
 */
class Cloud : public QGraphicsItem
{
public:

    /**
     * @brief Creates a new cloud
     * @param y - the y coordinate of the cloud
     */
    Cloud(int y);

    /**
     * @brief Destructor
     */
    ~Cloud();

    /**
     * @brief boundingRect of the graphicsitem
     * @return returns boundingRect
     */
    QRectF boundingRect() const;

    /**
     * @brief Used to draw graphicsitems to graphicsscene
     * @param painter - required as default
     * @param option - required as default
     * @param widget - required as default
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief Returns the speed of the cloud (pixels per tick)
     * @return speed_
     */
    int getSpeed();

private:
    QImage image_;
    int speed_ = 3; //pxls per tick
};

}

#endif // CLOUD_H
