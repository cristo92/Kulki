#include "ballnormal.h"

BallNormal::BallNormal(qreal x, qreal y, qreal w, qreal h, int myColor, int points, QGraphicsScene *scene,
           const QPen &pen, const QBrush &brush):
    Ball(x,y,w,h,myColor,scene,pen,brush), points(points)
{

}

bool BallNormal::isColor(QColor color) {
    return this->brush().color()==color;
}
int BallNormal::sumPoints() {
    return points;
}
int BallNormal::timesPoints() {
    return 1;
}
