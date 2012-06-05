#include "diagramscene.h"
#define DEBUG

DiagramScene::DiagramScene(QObject *parent, QLabel *windowStatusBar, qint32 n, qint32 k) :
    QGraphicsScene(parent), windowStatusBar(windowStatusBar), n(n), k(k)
{
    createPixmaps();
    sceneMode=false;
    firstEllipse=NULL;
    secondEllipse=NULL;
    this->setSceneRect(0,0,n*(RKULKI*2+ODLKULKI),n*(RKULKI*2+ODLKULKI));
    double X=ODLKULKI;
    double Y=ODLKULKI;
    int nrOfColor;
    for(int i=0; i<n; i++, X+=RKULKI*2+ODLKULKI) {
        Y=ODLKULKI;
        for(int j=0; j<n; j++, Y+=RKULKI*2+ODLKULKI) {
            nrOfColor=rand()%k;
            new BallNormal(X,Y,RKULKI*2,RKULKI*2,nrOfColor,nrOfColor+1,pixmaps[nrOfColor],this);//->setActive(true);
        }
    }
    this->update();
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Ball *ellipse = dynamic_cast<Ball*>(this->itemAt(event->scenePos()));
    switch(sceneMode) {
        case SECOND_BALL_CHOSEN:
            secondEllipse->lighten();
            if(ellipse==secondEllipse) {
                firstEllipse->lighten();
                swap(secondEllipse,firstEllipse);
                sceneMode=NOTHING_CHOSEN;
                break;
            }
            if(firstEllipse->isCloseTo(ellipse)) {
                secondEllipse = ellipse;
                secondEllipse->darken();
                break;
            }
            sceneMode=FIRST_BALL_CHOSEN;
            break;
        case FIRST_BALL_CHOSEN:
            if(firstEllipse->isCloseTo(ellipse)) {
                secondEllipse=ellipse;
                secondEllipse->darken();
                sceneMode=SECOND_BALL_CHOSEN;
                break;
            }
            firstEllipse->lighten();
            sceneMode=NOTHING_CHOSEN;
            break;
        case NOTHING_CHOSEN:
            if(ellipse!=NULL) {
                firstEllipse=ellipse;
                firstEllipse->darken();
                sceneMode=FIRST_BALL_CHOSEN;
            }
    }
}
void DiagramScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    mousePressEvent(event);
}

void DiagramScene::swap(Ball *ellipse1, Ball *ellipse2)
{
    QPointF temp = ellipse1->scenePos();
    QPropertyAnimation animation1(ellipse1,"pos");
    animation1.setStartValue(ellipse1->pos());
    animation1.setEndValue(ellipse2->pos());
    QPropertyAnimation animation2(ellipse2,"pos");
    animation2.setStartValue(ellipse1->pos());
    animation2.setEndValue(ellipse1->pos());
    QAnimationGroup animationGroup;
    animationGroup.addAnimation(&animation1);
    animationGroup.addAnimation(&animation2);
    animationGroup.start(QAbstractAnimation::DeleteWhenStopped);

    this->update(ellipse1->scenePos().rx(),ellipse1->scenePos().ry(),RKULKI,RKULKI);
    this->update(ellipse2->scenePos().rx(),ellipse2->scenePos().ry(),RKULKI,RKULKI);
    events.push_back(qMakePair(ellipse1,MOVE_BALL_EVENT));
    events.push_back(qMakePair(ellipse2,MOVE_BALL_EVENT));
    nextTurn();
}

int DiagramScene::LookForLine(Ball *ball, qreal addX, qreal addY, int &add, int &times) {
    qreal X=ball->scenePos().rx();
    qreal Y=ball->scenePos().ry();
    Ball *nextBall=ball;
    int ret=0;
    do {
        ret++;
        add += ball->sumPoints();
        times *= ball->timesPoints();
        X += addX;
        Y += addY;
        nextBall = dynamic_cast<Ball*>(this->itemAt(X,Y));
    } while(nextBall!=NULL && ball->compareColor(nextBall));
    return ret;
}

void DiagramScene::vanishLine(Ball *ball, qreal addX, qreal addY) {
    qreal X=ball->scenePos().rx()+addX;
    qreal Y=ball->scenePos().ry()+addY;
    Ball *nextBall=dynamic_cast<Ball*>(this->itemAt(X,Y));
    while(nextBall!=NULL && ball->compareColor(nextBall)) {
        events.push_back(qMakePair(nextBall,MOVE_BALL_EVENT));
        X+=addX;
        Y+=addY;
        nextBall=dynamic_cast<Ball*>(this->itemAt(X,Y));
    }
}

void DiagramScene::moveBallEvent(Ball *ball) {
    qDebug() << "MoveBallEvent:Ball at posision: " << ball->scenePos().rx() << " " << ball->scenePos().ry();

    //horizontal Looking
    int addH = 0;
    int timesH = 1;
    int dlgH = -1;
    dlgH += LookForLine(ball,RKULKI*2+ODLKULKI,0.0,addH,timesH);
    dlgH += LookForLine(ball,-(RKULKI*2+ODLKULKI),0.0,addH,timesH);
    if(dlgH<3) {addH=0; timesH=1;}
    else {
        vanishLine(ball,RKULKI*2+ODLKULKI,0.0);
        vanishLine(ball,-(RKULKI*2+ODLKULKI),0.0);
    }
    //vertical Looking
    int addV = 0;
    int timesV = 1;
    int dlgV = -1;
    dlgV += LookForLine(ball,0.0,RKULKI*2+ODLKULKI,addV,timesV);
    dlgV += LookForLine(ball,0.0,-(RKULKI*2+ODLKULKI),addV,timesV);
    if(dlgV<3) {addV=0; timesV=1;}
    else {
        vanishLine(ball,0.0,RKULKI*2+ODLKULKI);
        vanishLine(ball,0.0,-(RKULKI*2+ODLKULKI));
    }
    if(dlgH>=3 || dlgV>=3) events.push_back(qMakePair(ball,VANISH_BALL_EVENT));

    char str[10];
    std::sprintf(str,"%d",(addH+addV)*timesH*timesV);
    windowStatusBar->setText(QString(str));
    #ifndef DEBUG
#endif
}

void DiagramScene::vanishBallEvent(Ball *ball)
{
    qDebug() << "VanishBallEvent:Ball at posision: " << ball->scenePos().rx() << " " << ball->scenePos().ry();
    QPointF point = ball->scenePos();
    this->removeItem(ball);
    this->update(point.rx(),point.ry(),RKULKI*2.0,RKULKI*2.0);
}

void DiagramScene::nextTurn()
{
    for(; events.size(); events.pop_front()) {
        if(events.front().second==MOVE_BALL_EVENT) moveBallEvent(events.front().first);
        else if(events.front().second==VANISH_BALL_EVENT) vanishBallEvent(events.front().first);
    }
}

void DiagramScene::createPixmaps()
{
    pixmaps.push_back(QPixmap("images/redball.jpg"));
    pixmaps.push_back(QPixmap("images/greenball.jpg"));
    pixmaps.push_back(QPixmap("images/blueball.jpg"));
    pixmaps.push_back(QPixmap("images/yellowball.jpg"));
    pixmaps.push_back(QPixmap("images/magentaball.jpg"));
    pixmaps.push_back(QPixmap("images/cyanball.jpg"));
    pixmaps.push_back(QPixmap("images/greyball.jpg"));
}


