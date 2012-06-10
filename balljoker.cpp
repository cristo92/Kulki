#include "balljoker.h"

BallJoker::BallJoker(qreal x, qreal y, qreal w, qreal h, int myColor, int points):
    Ball(x,y,w,h,myColor), points(points)
{
    myPixmap = *jokerPixmap;
}

QPixmap *BallJoker::jokerPixmap;
QPixmap *BallJoker::jokerChosenPixmap;
