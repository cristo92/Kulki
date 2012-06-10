#ifndef BALLBONUS_H
#define BALLBONUS_H

#include <QtGui>
#include "ball.h"

class BallBonus : public Ball
{
    Q_OBJECT
public:
    explicit BallBonus(qreal x, qreal y, qreal w, qreal h, int myColor, int points = 0): Ball(x,y,w,h,myColor){}
    ~BallBonus(){}
    bool compareColorWithoutRecursion(Ball *ball) {return myColor==ball->myColor;}
    bool compareColor(Ball *ball) {
        if(ball==NULL) return false;
        return (myColor==ball->myColor) || ball->compareColorWithoutRecursion(this);
    }
    int sumPoints() {return 0;}
    int timesPoints() {return 2;}
    void updateAfterMove() {}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        Ball::paint(painter,option,widget);
        painter->drawPixmap(QRect(0,0,RKULKI*2,RKULKI*2),*bonusPixmap,bonusPixmap->rect());
    }

    static QPixmap *bonusPixmap;

private:
};


#endif // BALLBONUS_H
