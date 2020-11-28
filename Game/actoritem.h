#ifndef ACTORITEM_H
#define ACTORITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

/**
 *@file
 *@brief
 */

namespace Student {

/**
 * @brief The ActorItem class defines the type and graphics of different logic actors
 */
class ActorItem : public QGraphicsItem
{
public:

    /**
     * @brief
     * @param x - the x-coordinate of the actor
     * @param y - the y-coordinate of the actor
     * @param defines the type of the actor: 0 = passenger, 1 = nysse, 2 = destroyed nysse
     */
    ActorItem(int x, int y, int type);

    /**
      *@brief destructor
      */
    ~ActorItem();

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
     * @brief getType returns the type of the actoritem: 0 = passenger, 1 = nysse, 2 = destroyed nysse
     * @return type of the actoritem
     */
    int getType();

    /**
     * @brief setType changes the type of the actoritem
     * @param type - new type of the actor
     */
    void setType(int type);

private:
    QImage image_;
    int type_;
};

}
#endif // ACTORITEM_H
