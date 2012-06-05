#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QtGui>
#include <cstdio>
#include <ctime>
#include "ball.h"
#include "ballnormal.h"


class DiagramScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum {NOTHING_CHOSEN,FIRST_BALL_CHOSEN,SECOND_BALL_CHOSEN};
    enum ballEventsEnum {MOVE_BALL_EVENT,VANISH_BALL_EVENT};
    explicit DiagramScene(QObject *parent = 0, QLabel *windowStatusBar = 0, qint32 n = 7, qint32 k = 7);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void swap(Ball *ellipse1, Ball *ellipse2);
    int LookForLine(Ball *ball, qreal addX, qreal addY, int &add, int &times);
    void vanishLine(Ball *ball, qreal addX, qreal addY);
    void moveBallEvent(Ball *ball);
    void vanishBallEvent(Ball *ball);
    void nextTurn();

    int n,k;
    
signals:

public slots:

private:
    void createPixmaps();
    int sceneMode;
    QLabel *windowStatusBar;
    QVector<QPixmap> pixmaps;
    Ball *firstEllipse, *secondEllipse;
    QQueue<QPair<Ball*,ballEventsEnum> > events;
};
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};


#endif // DIAGRAMSCENE_H
