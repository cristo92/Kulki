#ifndef BALL_H
#define BALL_H

#include <QtGui>
#include <cmath>

const int RKULKI = 15;
const int ODLKULKI = 5;
class Ball : public QGraphicsPixmapItem
{
public:
    explicit Ball(qreal x, qreal y, qreal w, qreal h, int myColor, QPixmap pixmap, QGraphicsScene *scene=0);
    void darken(){
        this->setPixmap(*pixmaps[myColor+chosenColor]);
        qDebug() << myColor << " " << myColor+chosenColor;
    }
    void lighten(){this->setPixmap(*pixmaps[myColor]);}

    virtual bool compareColorWithoutRecursion(Ball *ball) = 0;
    virtual bool compareColor(Ball *ball) = 0;
    virtual int sumPoints() = 0;
    virtual int timesPoints() = 0;
    virtual void updateAfterMove() = 0;

    static void createPixmaps();
    bool isCloseTo(Ball *ellipse);
    int myColor;

protected:
    static QPixmap *pixmaps[14];
    static QColor colors[14];
    static int chosenColor;
};

#endif // BALL_H
