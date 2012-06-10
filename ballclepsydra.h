#ifndef BALLCLEPSYDRA_H
#define BALLCLEPSYDRA_H

#include <QtGui>
#include "ball.h"

class BallClepsydra : public Ball
{
    Q_OBJECT
public:
    explicit BallClepsydra(qreal x, qreal y, qreal w, qreal h, int myColor, int points = 0): Ball(x,y,w,h,myColor){index=5;}
    ~BallClepsydra(){}
    bool compareColorWithoutRecursion(Ball *ball) {return myColor==ball->myColor;}
    bool compareColor(Ball *ball) {
        if(ball==NULL) return false;
        return (myColor==ball->myColor) || ball->compareColorWithoutRecursion(this);
    }
    int sumPoints() {return points[index];}
    int timesPoints() {return 1;}
    void updateAfterMove() {
        if(index) index--;
        this->update();
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        Ball::paint(painter,option,widget);
        painter->drawPixmap(QRect(0,0,RKULKI*2,RKULKI*2),*pixmaps[index],pixmaps[index]->rect());
    }

    static QPixmap *pixmaps[6];
    static int points[6];

private:
    int index;
};

#endif // BALLCLEPSYDRA_H
