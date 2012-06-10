#ifndef BALLSKULL_H
#define BALLSKULL_H

#include <QtGui>
#include "ball.h"

class BallSkull : public Ball
{
    Q_OBJECT
public:
    explicit BallSkull(qreal x, qreal y, qreal w, qreal h, int myColor): Ball(x,y,w,h,myColor){}
    ~BallSkull(){}
    bool compareColorWithoutRecursion(Ball *ball) {return myColor==ball->myColor;}
    bool compareColor(Ball *ball) {
        if(ball==NULL) return false;
        return (myColor==ball->myColor) || ball->compareColorWithoutRecursion(this);
    }
    int sumPoints() {return 0;}
    int timesPoints() {return 0;}
    void updateAfterMove() {}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        Ball::paint(painter,option,widget);
        painter->drawPixmap(QRect(0,0,RKULKI*2,RKULKI*2),*skullPixmap,skullPixmap->rect());
    }

    static QPixmap *skullPixmap;

private:
};


#endif // BALLSKULL_H
