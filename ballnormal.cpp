#include "ballnormal.h"

BallNormal::BallNormal(qreal x, qreal y, qreal w, qreal h, int myColor, int points, QPixmap pixmap, QGraphicsScene *scene):
    Ball(x,y,w,h,myColor,pixmap,scene), points(points)
{

}

bool BallNormal::compareColorWithoutRecursion(Ball *ball) {
    return myColor==ball->myColor;
}
bool BallNormal::compareColor(Ball *ball) {
    if(ball==NULL) return false;
    return (myColor==ball->myColor) || ball->compareColorWithoutRecursion(this);
}
int BallNormal::sumPoints() {
    return points;
}
int BallNormal::timesPoints() {
    return 1;
}
