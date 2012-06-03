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
    /*void darken() {this->setBrush(QBrush(this->brush().color().darker(200)));
                   qDebug() << "is valid " << this->brush().color().darker(200).isValid();}
    void lighten() {this->setBrush(QBrush(this->brush().color().lighter(200)));}*/

    virtual bool isColor(QColor color) = 0;
    virtual int sumPoints() = 0;
    virtual int timesPoints() = 0;
    virtual void updateAfterMove() = 0;

    static void createPixmaps();
    bool isCloseTo(Ball *ellipse);

protected:
    static QPixmap *pixmaps[14];
    static QColor colors[14];
    static int chosenColor;
    int myColor;
};

#endif // BALL_H
