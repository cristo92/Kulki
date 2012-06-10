#ifndef BALLKAMELEON_H
#define BALLKAMELEON_H

#include <QtGui>
#include "ball.h"

class BallKameleon : public Ball
{
    Q_OBJECT
public:
    explicit BallKameleon(qreal x, qreal y, qreal w, qreal h, int myColor, int points, int maxColors);
    ~BallKameleon(){}
    bool compareColorWithoutRecursion(Ball *ball);
    bool compareColor(Ball *ball);
    int sumPoints();
    int timesPoints();
    void updateAfterMove();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    static QPixmap *kameleonPixmap;

private:
    int points;
    int maxColors;
};

#endif // BALLKAMELEON_H
