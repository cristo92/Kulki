#ifndef BALLNORMAL_H
#define BALLNORMAL_H

#include <QtGui>
#include "ball.h"

class BallNormal : public Ball
{
    Q_OBJECT
public:
    explicit BallNormal(qreal x, qreal y, qreal w, qreal h, int myColor, int points);
    ~BallNormal(){}
    bool compareColorWithoutRecursion(Ball *ball);
    bool compareColor(Ball *ball);
    int sumPoints();
    int timesPoints();
    void updateAfterMove(){}

private:
    int points;
};

#endif // BALLNORMAL_H
