#ifndef BALL_H
#define BALL_H

#include <QtGui>
#include <cmath>

const int RKULKI = 30;
const int ROBRAZKA = 30;
const int ODLKULKI = 5;
const int INTERVAL = RKULKI*2+ODLKULKI;
class Ball : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit Ball(qreal x, qreal y, qreal w, qreal h, int myColor);
    ~Ball(){}
    virtual void darken(){
        myPixmap=*pixmaps[myColor+chosenColor];
        this->update();
    }
    void remove() {removed=true;}
    bool isRemoved() {return removed;}

    virtual bool compareColorWithoutRecursion(Ball *ball) = 0;
    virtual bool compareColor(Ball *ball) = 0;
    virtual int sumPoints() = 0;
    virtual int timesPoints() = 0;
    virtual void updateAfterMove() = 0;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    static void createPixmaps();
    bool isCloseTo(Ball *ellipse);
    int myColor;
    int howFarToGround;

public slots:
    virtual void lighten(){
        myPixmap=*pixmaps[myColor];
        this->update();
    }

protected:
    QPixmap myPixmap;
    bool removed;
    static QPixmap *pixmaps[14];
    static QColor colors[14];
    static int chosenColor;
};

#endif // BALL_H
