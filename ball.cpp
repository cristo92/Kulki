#include "ball.h"

Ball::Ball(qreal x, qreal y, qreal w, qreal h, int myColor):
    QGraphicsWidget(), myColor(myColor), myPixmap(*pixmaps[myColor]), howFarToGround(0), removed(false)
{
    this->setX(x);
    this->setY(y);
    this->setPreferredHeight(RKULKI*2.0);
    this->setPreferredWidth(RKULKI*2.0);
    this->setActive(true);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(QRect(0.0,0.0,RKULKI*2.0,RKULKI*2.0),myPixmap,myPixmap.rect());
}

void Ball::createPixmaps() {
    pixmaps[0]=new QPixmap("images/redball.gif");
    pixmaps[1]=new QPixmap("images/greenball.gif");
    pixmaps[2]=new QPixmap("images/blueball.gif");
    pixmaps[3]=new QPixmap("images/yellowball.gif");
    pixmaps[4]=new QPixmap("images/magentaball.gif");
    pixmaps[5]=new QPixmap("images/cyanball.gif");
    pixmaps[6]=new QPixmap("images/greyball.jpg");
    pixmaps[7]=new QPixmap("images/redballchosen.gif");
    pixmaps[8]=new QPixmap("images/greenballchosen.gif");
    pixmaps[9]=new QPixmap("images/blueballchosen.gif");
    pixmaps[10]=new QPixmap("images/yellowballchosen.gif");
    pixmaps[11]=new QPixmap("images/magentaballchosen.gif");
    pixmaps[12]=new QPixmap("images/cyanballchosen.gif");
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


