#include "ballkameleon.h"

BallKameleon::BallKameleon(qreal x, qreal y, qreal w, qreal h, int myColor, int points, int maxColors):
    Ball(x,y,w,h,myColor), points(points), maxColors(maxColors)
{
}

QPixmap *BallKameleon::kameleonPixmap;

bool BallKameleon::compareColorWithoutRecursion(Ball *ball) {
    return myColor==ball->myColor;
}
bool BallKameleon::compareColor(Ball *ball) {
    if(ball==NULL) return false;
    return (myColor==ball->myColor) || ball->compareColorWithoutRecursion(this);
}
int BallKameleon::sumPoints() {
    return points;
}
int BallKameleon::timesPoints() {
    return 1;
}
void BallKameleon::updateAfterMove() {
    myColor = rand()%maxColors;
    myPixmap = *pixmaps[myColor];
    this->update();
}
void BallKameleon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Ball::paint(painter,option,widget);
    painter->drawPixmap(QRect(0,0,RKULKI*2,RKULKI*2),*kameleonPixmap,kameleonPixmap->rect());
}
