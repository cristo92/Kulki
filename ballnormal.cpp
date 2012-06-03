#include "ballnormal.h"

BallNormal::BallNormal(qreal x, qreal y, qreal w, qreal h, int myColor, int points, QPixmap pixmap, QGraphicsScene *scene):
    Ball(x,y,w,h,myColor,pixmap,scene), points(points)
{

}

int BallNormal::sumPoints() {
    return points;
}
int BallNormal::timesPoints() {
    return 1;
}
