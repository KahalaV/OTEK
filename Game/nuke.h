#ifndef NUKE_H
#define NUKE_H

#include "bomb.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

/**
 *@file
 *@brief
 */

namespace Student {

/**
 * @brief The Nuke class defines the nuke that player can collect and drop with R key. Only one nuke can exist at a time
 */
class Nuke : public QGraphicsItem
{
public:

    /**
     * @brief Creates the nuke
     */
    Nuke();

    /**
     * @brief Destructor
     */
    ~Nuke();

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
     * @brief Checks if the nuke has exploded (exploded_ is true)
     * @return exploded_
     */
    bool isExploded();

    /**
     * @brief getDropTime returns current drop time integer of the bomb. The integer decreases as the bomb falls
     * @return current dropTime_
     */
    int getDropTime();

    /**
     * @brief getExplosionTime returns the current explosion time integer of the bomb. The integer increases as the explosion goes on
     * @return current explosionTime_
     */
    int getExplosionTime();

    /**
     * @brief Decrease the drop time integer of the bomb by 1
     */
    void decreaseDropTime();

    /**
     * @brief Increase the explosion time integer of the bomb by 1
     */
    void increaseExplosionTime();

    /**
     * @brief Sets the boolean exploded_ to true and changes the bomb graphic to explosion graphic
     */
    void explode();

    /**
     * @brief Sets the direction of the bomb graphic. 1 = north, 2 = northeast, 3 = east etc.
     * @param dir: new direction of the bomb
     */
    void setDirection(int dir);

    /**
     * @brief Sets the status of the nuke (0 = no nuke in game, 1 = spawned on map, 2 = with player, 3 = dropping)
     * @param new status
     */
    void setStatus(int status);

    /**
     * @brief Returns the current status of the nuke
     * @return status_
     */
    int getStatus();

private:
    QImage image_;
    int dir_;
    int status_; //0 = no nuke in game, 1 = spawned on map, 2 = with player, 3 = droppin
    bool exploded_;
    int dropTime_;
    int explosionTime_;
};

}

#endif // NUKE_H
