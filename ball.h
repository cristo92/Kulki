#ifndef BALL_H
#define BALL_H

#include <QtGui>

class Ball : public QGraphicsEllipseItem
{
public:
    explicit Ball(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0,
                  QGraphicsScene *scene = 0, const QPen & pen = QPen(), const QBrush & brush = QBrush());
    virtual bool isColor(QColor color) = 0;
    virtual int sumPoints() = 0;
    virtual int timesPoints() = 0;
    virtual void updateAfterMove() = 0;

};

#endif // BALL_H
