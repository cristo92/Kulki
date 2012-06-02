#include "ball.h"

Ball::Ball(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent, QGraphicsScene *scene,
           const QPen &pen, const QBrush &brush):
    QGraphicsEllipseItem(x,y,w,h,parent,scene)
{
    this->setPen(pen);
    this->setBrush(brush);
}
