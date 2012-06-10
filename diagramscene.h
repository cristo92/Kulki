#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QtGui>
#include <cstdio>
#include <ctime>
#include "ball.h"
#include "ballnormal.h"
#include "ballkameleon.h"
#include "balljoker.h"
#include "ballskull.h"
#include "ballbonus.h"
#include "ballclepsydra.h"
#include "player.h"


class DiagramScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum {NOTHING_CHOSEN,FIRST_BALL_CHOSEN,SECOND_BALL_CHOSEN};
    enum ballNames {CAMELEON_BALL,JOKER_BALL,BONUS_BALL,SKULL_BALL,CLEPSYDRA_BALL};
    enum ballEventsEnum {MOVE_BALL_EVENT,VANISH_BALL_EVENT,FALL_BALL_EVENT,APPEAR_BALL_EVENT};
    explicit DiagramScene(QObject *parent = 0, QLabel *windowStatusBar = 0, qint32 n = 7, qint32 k = 7);
    ~DiagramScene(){}
    bool isGoodMove(Ball *ball, int X, int Y, int forbiddenX, int forbiddenY);
    void computerMove(Ball *ball1, Ball *ball2);
    void makeComputerMove();
    void reConstruct(int size, int colors, bool mode, int percentage, int *percentageTab);
    Ball *generateBall(qreal X, qreal Y, int color, bool canBeJoker);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void swap(Ball *ellipse1, Ball *ellipse2);
    int LookForLine(Ball *ball, qreal X, qreal Y, qreal addX, qreal addY, qreal forbiddenX, qreal forbiddenY);
    int LookForLine(Ball *ball, qreal addX, qreal addY);
    void vanishLine(Ball *ball, qreal addX, qreal addY);
    void moveBallEvent(Ball *ball);
    void vanishBallEvent(Ball *ball);
    void fallBallEvent(Ball *ball);
    void appearBallEvent();
    void updateStatusBar();
    void updateBalls();
    void updateMoveEverything();
    void updatePlayers();

    static int numberOfTypes;
    int sizeOfScene,numberOfColors;
    Player *activePlayer,*disactivePlayer;
    bool aloneMode;
    int pcBonusBalls;
    int pcBallsTab[5];
    int pcBallsSums[5];
    int thisTurnPoints, thisTurnAddPoints, thisTurnTimesPoints;
    static int maximumSizeOfDiagramScene;

public slots:

    
signals:

public slots:
    void nextTurn();
    void nextAction();

private:
    void createPixmaps();
    int tIsAVeryBadNameForVariable;
    int sceneMode;
    QLabel *windowStatusBar;
    QVector<QPixmap> pixmaps;
    Ball *firstEllipse, *secondEllipse;
    QQueue<QPair<Ball*,ballEventsEnum> > eventsMV;
    QQueue<QPair<Ball*,ballEventsEnum> > eventsF;
    QVector<Ball*> removedBalls;
    QVector<int> appearBallTab;
    QParallelAnimationGroup *animationGroup;
};
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};


#endif // DIAGRAMSCENE_H
