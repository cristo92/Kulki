#ifndef BALLNORMAL_H
#define BALLNORMAL_H

#include <QtGui>
#include "ball.h"

class BallNormal : public Ball
{
public:
    explicit BallNormal(qreal x, qreal y, qreal w, qreal h, int myColor, int points, QGraphicsScene *scene=0,
                  const QPen & pen = QPen(), const QBrush & brush = QBrush());
    bool isColor(QColor color);
    int sumPoints();
    int timesPoints();
    void updateAfterMove(){}
private:
    int points;
};

#endif // BALLNORMAL_H
