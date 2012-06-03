#include "ball.h"

Ball::Ball(qreal x, qreal y, qreal w, qreal h, int myColor, QGraphicsScene *scene,
           const QPen &pen, const QBrush &brush):
    QGraphicsEllipseItem(x,y,w,h,NULL,scene), myColor(myColor)
{
    this->setPen(pen);
    this->setBrush(brush);
}

QColor Ball::colors[14] = {
    Qt::red,Qt::green,Qt::blue,Qt::yellow,Qt::magenta,Qt::cyan,Qt::gray,
    Qt::darkRed,Qt::darkGreen,Qt::darkBlue,Qt::darkYellow,Qt::darkMagenta,Qt::darkCyan,Qt::darkGray};
