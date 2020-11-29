#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

/**
 *@file
 *@brief
 */

namespace Student {

/**
 * @brief Bomb class defines bombs that player has dropped
 */
class Bomb : public QGraphicsItem
{
public:

    /**
     * @brief Creates a new bomb item
     */
    Bomb();

    /**
     * @brief Destructor
     */
    ~Bomb();

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
     * @brief isExploded checks if the bomb has exploded or if it is still falling
     * @return true if bomb has exploded, false if bomb is still falling
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

private:
    QImage image_;
    int dir_;
    int dropTime_;
    int explosionTime_;
    bool exploded_;
};

}

#endif // BOMB_H

