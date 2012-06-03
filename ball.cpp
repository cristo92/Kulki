#include "ball.h"

Ball::Ball(qreal x, qreal y, qreal w, qreal h, int myColor, QPixmap pixmap, QGraphicsScene *scene):
    QGraphicsPixmapItem(pixmap, NULL, scene), myColor(myColor)
{
    this->setX(x);
    this->setY(y);
    this->setActive(true);
}

void Ball::createPixmaps() {
    pixmaps[0]=new QPixmap("images/redball.jpg");
    pixmaps[1]=new QPixmap("images/greenball.jpg");
    pixmaps[2]=new QPixmap("images/blueball.jpg");
    pixmaps[3]=new QPixmap("images/yellowball.jpg");
    pixmaps[4]=new QPixmap("images/magentaball.jpg");
    pixmaps[5]=new QPixmap("images/cyanball.jpg");
    pixmaps[6]=new QPixmap("images/greyball.jpg");
    pixmaps[7]=new QPixmap("images/redballchosen.jpg");
    pixmaps[8]=new QPixmap("images/greenballchosen.jpg");
    pixmaps[9]=new QPixmap("images/blueballchosen.jpg");
    pixmaps[10]=new QPixmap("images/yellowballchosen.jpg");
    pixmaps[11]=new QPixmap("images/magentaballchosen.jpg");
    pixmaps[12]=new QPixmap("images/cyanballchosen.jpg");
    pixmaps[13]=new QPixmap("images/greyballchosen.jpg");
}
bool Ball::isCloseTo(Ball *ellipse) {
    if(ellipse==NULL) return false;
    return abs(ellipse->scenePos().rx() - this->scenePos().rx()) + abs(ellipse->scenePos().ry()-this->scenePos().ry()) <
            RKULKI*2+ODLKULKI*2;
}

QPixmap *Ball::pixmaps[14];
QColor Ball::colors[14] = {
    Qt::red,Qt::green,Qt::blue,Qt::yellow,Qt::magenta,Qt::cyan,Qt::gray,
    Qt::darkRed,Qt::darkGreen,Qt::darkBlue,Qt::darkYellow,Qt::darkMagenta,Qt::darkCyan,Qt::darkGray};
int Ball::chosenColor = 7;


