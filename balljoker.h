#ifndef BALLJOKER_H
#define BALLJOKER_H

#include <QtGui>
#include "ball.h"

class BallJoker : public Ball
{
    Q_OBJECT
public:
    explicit BallJoker(qreal x, qreal y, qreal w, qreal h, int myColor = 0, int points = 0);
    ~BallJoker(){}
    bool compareColorWithoutRecursion(Ball *) {return true;}
    bool compareColor(Ball *) {return true;}
    int sumPoints() {return 0;}
    int timesPoints() {return 1;}
    void updateAfterMove() {}
    void lighten() {myPixmap=*jokerPixmap; this->update();}
    void darken() {myPixmap=*jokerChosenPixmap; this->update();}

    static QPixmap *jokerPixmap,*jokerChosenPixmap;

private:
    int points;
};

#endif // BALLJOKER_H
