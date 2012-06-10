#include "diagramscene.h"
#define DEBUG

DiagramScene::DiagramScene(QObject *parent, QLabel *windowStatusBar, qint32 n, qint32 k) :
    QGraphicsScene(parent),
    windowStatusBar(windowStatusBar), sizeOfScene(n), numberOfColors(k)
{
    createPixmaps();
    sceneMode = false;
    firstEllipse = NULL;
    secondEllipse = NULL;
    appearBallTab = QVector<int>(maximumSizeOfDiagramScene,0);
    animationGroup = new QParallelAnimationGroup(this);
    connect(animationGroup,SIGNAL(finished()),this,SLOT(nextAction()));

    for(int i=0; i<numberOfTypes; i++) pcBallsTab[i] = 1;

    reConstruct(n,k,false,20,pcBallsTab);
}

int DiagramScene::LookForLine(Ball *ball, qreal X, qreal Y, qreal addX, qreal addY, qreal forbiddenX, qreal forbiddenY) {
    if(X==forbiddenX && Y==forbiddenY) return 0;
    int ret=0;
    Ball *nextBall = dynamic_cast<Ball*>(this->itemAt(X,Y));
    while(nextBall!=NULL && ball->compareColor(nextBall)) {
        ret++;
        X += addX;
        Y += addY;
        nextBall = dynamic_cast<Ball*>(this->itemAt(X,Y));
    }
    qDebug () << "LookForLine: " << X << " " << Y << " " << ret;
    return ret;
}

bool DiagramScene::isGoodMove(Ball *ball, int X, int Y, int forbiddenX, int forbiddenY) {
    if(this->itemAt(forbiddenX,forbiddenY)!=NULL) qDebug() << "isGoodMove";
    if(this->itemAt(X,Y)==NULL) return false;
    if(LookForLine(ball,X+RKULKI*2+ODLKULKI,Y,RKULKI*2+ODLKULKI,0,forbiddenX,forbiddenY) +
            LookForLine(ball,X-RKULKI*2-ODLKULKI,Y,-RKULKI*2-ODLKULKI,0,forbiddenX,forbiddenY) > 1) return true;
    if(LookForLine(ball,X,Y+RKULKI*2+ODLKULKI,0,RKULKI*2+ODLKULKI,forbiddenX,forbiddenY) +
            LookForLine(ball,X,Y-RKULKI*2-ODLKULKI,0,-RKULKI*2-ODLKULKI,forbiddenX,forbiddenY) > 1) return true;
    return false;
}

void DiagramScene::computerMove(Ball *ball1, Ball *ball2) {
    qDebug() << "computerMove";
    if(ball1==NULL || ball2==NULL) return;
    ball1->darken();
    ball2->darken();
    swap(ball1,ball2);
}

void DiagramScene::makeComputerMove()
{
    QList<QGraphicsItem*> list = this->items();
    qDebug() << "makeComputerMove " << list.size();
    QGraphicsItem* itemNotBall;
    Ball *item;
    qreal X;
    qreal Y;
    foreach(itemNotBall,list) {
        X = itemNotBall->scenePos().rx();
        Y = itemNotBall->scenePos().ry();
        if(this->itemAt(X,Y)!=NULL) qDebug() << "is ok";
        item = dynamic_cast<Ball*>(itemNotBall);
        if(item==NULL) continue;
        if(isGoodMove(item,X+INTERVAL,Y,X,Y)) {
            computerMove(item,dynamic_cast<Ball*>(this->itemAt(X+INTERVAL,Y)));
            return;
        }
        if(isGoodMove(item,X-INTERVAL,Y,X,Y)) {
            computerMove(item,dynamic_cast<Ball*>(this->itemAt(X-INTERVAL,Y)));
            return;
        }
        if(isGoodMove(item,X,Y+INTERVAL,X,Y)) {
            computerMove(item,dynamic_cast<Ball*>(this->itemAt(X,Y+INTERVAL)));
            return;
        }
        if(isGoodMove(item,X,Y-INTERVAL,X,Y)) {
            computerMove(item,dynamic_cast<Ball*>(this->itemAt(X,Y-INTERVAL)));
            return;
        }
    }
    qDebug() << item->scenePos().rx() << " " << item->scenePos().ry();
    Ball *ball=dynamic_cast<Ball*>(this->itemAt(item->scenePos().rx()-INTERVAL,item->scenePos().ry()));
    if(ball!=NULL) computerMove(item,ball);
    ball=dynamic_cast<Ball*>(this->itemAt(item->scenePos().rx()+INTERVAL,item->scenePos().ry()));
    if(ball!=NULL) computerMove(item,ball);
    ball=dynamic_cast<Ball*>(this->itemAt(item->scenePos().rx(),item->scenePos().ry()+INTERVAL));
    if(ball!=NULL) computerMove(item,ball);
    ball=dynamic_cast<Ball*>(this->itemAt(item->scenePos().rx(),item->scenePos().ry()-INTERVAL));
    if(ball!=NULL) computerMove(item,ball);
}

void DiagramScene::reConstruct(int size, int colors, bool mode, int percentage, int *percentageTab)
{
    QList<QGraphicsItem*> list = this->items();
    QGraphicsItem* item;
    foreach(item,list) {
        this->removeItem(item);
        delete item;
    }

    sizeOfScene=size;
    numberOfColors=colors;
    aloneMode=mode;
    pcBonusBalls=percentage;
    for(int i=0; i<5; i++) pcBallsTab[i]=*(percentageTab+i);
    qDebug() << "ReConstruct: " << size << " " << numberOfColors << " " << aloneMode << " " << pcBonusBalls;
    qDebug() << pcBallsTab[0] << " " << pcBallsTab[1] << " " << pcBallsTab[2] << " " << pcBallsTab[3] << " " << pcBallsTab[4];

    int tab[sizeOfScene][sizeOfScene];

    double X=ODLKULKI;
    double Y=ODLKULKI;
    int nrOfColor;
    bool canBeJoker = true;
    Ball *ball;
    for(int i=0; i<sizeOfScene; i++, X+=RKULKI*2+ODLKULKI) {
        Y=ODLKULKI;
        for(int j=0; j<sizeOfScene; j++, Y+=RKULKI*2+ODLKULKI) {
            nrOfColor=rand()%numberOfColors;
            while((i>1 && tab[i-1][j]==nrOfColor && tab[i-2][j]==nrOfColor) ||
                  (j>1 && tab[i][j-1]==nrOfColor && tab[i][j-2]==nrOfColor)) {
                nrOfColor=rand()%numberOfColors;
                canBeJoker=false;
            }
            tab[i][j]=nrOfColor;

            ball=generateBall(X,Y,nrOfColor,canBeJoker);

            this->addItem(ball);
        }
    }
    this->update();
}

Ball *DiagramScene::generateBall(qreal X, qreal Y, int nrOfColor, bool canBeJoker)
{
    Ball *ball;
    int nrOfType;
    int pcJoker = pcBallsTab[JOKER_BALL];
    if(canBeJoker==false) pcBallsTab[JOKER_BALL] = 0;
    if(rand()%100<pcBonusBalls) {
        pcBallsSums[0] = pcBallsTab[0];
        for(int i=1; i<numberOfTypes; i++) pcBallsSums[i]=pcBallsSums[i-1]+pcBallsTab[i];
        int temp = rand()%pcBallsSums[numberOfTypes-1];

        for(int i=0; i<numberOfTypes; i++) {
            if(temp<pcBallsSums[i]) {nrOfType = i; break;}
        }
        switch (nrOfType)
        {
            case CAMELEON_BALL:
                ball = new BallKameleon(X,Y,RKULKI*2,RKULKI*2,nrOfColor,nrOfColor+1,numberOfColors);
                break;
            case JOKER_BALL:
                ball = new BallJoker(X,Y,RKULKI*2,RKULKI*2);
                break;
            case SKULL_BALL:
                ball = new BallSkull(X,Y,RKULKI*2,RKULKI*2,nrOfColor);
                break;
            case BONUS_BALL:
                ball = new BallBonus(X,Y,RKULKI*2,RKULKI*2,nrOfColor);
                break;
            case CLEPSYDRA_BALL:
                ball = new BallClepsydra(X,Y,RKULKI*2,RKULKI*2,nrOfColor);
                break;
        }
    }
    else ball = new BallNormal(X,Y,RKULKI*2,RKULKI*2,nrOfColor,nrOfColor+1);

    pcBallsTab[JOKER_BALL] = pcJoker;
    return ball;
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(activePlayer->returnType()==Player::COMPUTER) return;
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
    eventsMV.push_back(qMakePair(ellipse1,MOVE_BALL_EVENT));
    eventsMV.push_back(qMakePair(ellipse2,MOVE_BALL_EVENT));

    QPropertyAnimation *animation1 = new QPropertyAnimation(ellipse1,"pos");
    animation1->setStartValue(ellipse1->pos());
    animation1->setEndValue(ellipse2->pos());
    if(activePlayer->returnType()==Player::COMPUTER) animation1->setDuration(1000);
    QPropertyAnimation *animation2 = new QPropertyAnimation(ellipse2,"pos");
    animation2->setStartValue(ellipse2->pos());
    animation2->setEndValue(ellipse1->pos());
    if(activePlayer->returnType()==Player::COMPUTER) animation2->setDuration(1000);
    QParallelAnimationGroup *smallAnimationGroup = new QParallelAnimationGroup();
    smallAnimationGroup->addAnimation(animation1);
    smallAnimationGroup->addAnimation(animation2);
    connect(smallAnimationGroup,SIGNAL(finished()),this,SLOT(nextTurn()));
    connect(smallAnimationGroup,SIGNAL(finished()),ellipse1,SLOT(lighten()));
    connect(smallAnimationGroup,SIGNAL(finished()),ellipse2,SLOT(lighten()));
    smallAnimationGroup->start(QAbstractAnimation::DeleteWhenStopped);
}

int DiagramScene::LookForLine(Ball *ball, qreal addX, qreal addY) {
    qreal X=ball->scenePos().rx();
    qreal Y=ball->scenePos().ry();
    Ball *nextBall=ball;
    int ret=0;
    do {
        ret++;
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
        eventsMV.push_back(qMakePair(nextBall,MOVE_BALL_EVENT));
        X+=addX;
        Y+=addY;
        nextBall=dynamic_cast<Ball*>(this->itemAt(X,Y));
    }
}

void DiagramScene::moveBallEvent(Ball *ball) {
    if(ball->isRemoved()) return;

    //horizontal Looking
    int dlgH = -1;
    dlgH += LookForLine(ball,RKULKI*2+ODLKULKI,0.0);
    dlgH += LookForLine(ball,-(RKULKI*2+ODLKULKI),0.0);
    if(dlgH<3);
    else {
        vanishLine(ball,RKULKI*2+ODLKULKI,0.0);
        vanishLine(ball,-(RKULKI*2+ODLKULKI),0.0);
    }
    //vertical Looking
    int dlgV = -1;
    dlgV += LookForLine(ball,0.0,RKULKI*2+ODLKULKI);
    dlgV += LookForLine(ball,0.0,-(RKULKI*2+ODLKULKI));
    if(dlgV<3);
    else {
        vanishLine(ball,0.0,RKULKI*2+ODLKULKI);
        vanishLine(ball,0.0,-(RKULKI*2+ODLKULKI));
    }
    if(dlgH>=3 || dlgV>=3) eventsMV.push_back(qMakePair(ball,VANISH_BALL_EVENT));

    #ifndef DEBUG
#endif
}

void DiagramScene::vanishBallEvent(Ball *ball)
{
    if(ball->isRemoved()) return;
    qreal X=ball->scenePos().rx();
    qreal Y=ball->scenePos().ry();
    appearBallTab[X/(RKULKI*2+ODLKULKI)]++;
    Ball *tempBall;
    for(; Y>0.0; Y-=RKULKI*2.0+ODLKULKI) {
        tempBall = dynamic_cast<Ball*>(this->itemAt(X,Y));
        if(tempBall==NULL) continue;
        tempBall->howFarToGround++;
        eventsF.push_back(qMakePair(tempBall,FALL_BALL_EVENT));
    }

    QPointF point = ball->scenePos();
    thisTurnAddPoints += ball->sumPoints();
    thisTurnTimesPoints *= ball->timesPoints();
    this->removeItem(ball);
    ball->remove();
    removedBalls.push_back(ball);
    this->update(point.rx(),point.ry(),RKULKI*2.0,RKULKI*2.0);
}

void DiagramScene::fallBallEvent(Ball *ball)
{
    if(ball->isRemoved() || ball->howFarToGround==0) return;

    QPropertyAnimation *animation = new QPropertyAnimation(ball,"pos");
    animation->setDuration(250 * ball->howFarToGround);
    animation->setStartValue(ball->scenePos());
    animation->setEndValue( QPointF(ball->scenePos().rx(),
                                    ball->scenePos().ry() + (RKULKI*2.0+ODLKULKI) * ball->howFarToGround));
    animationGroup->addAnimation(animation);
    ball->howFarToGround = 0;
    eventsMV.push_back(qMakePair(ball,MOVE_BALL_EVENT));
}

void DiagramScene::appearBallEvent()
{
    if(aloneMode) return;
    for(int i=0; i<sizeOfScene; i++) {
        for(int j=appearBallTab[i]; j>0; j--) {
            int nrOfColor = rand() % numberOfColors;
            Ball *ball = generateBall(ODLKULKI + (RKULKI*2.0+ODLKULKI)*i, ODLKULKI - (RKULKI*2.0+ODLKULKI)*j,
                                        nrOfColor,true);
            this->addItem(ball);
            QPropertyAnimation *animation = new QPropertyAnimation(ball,"pos");
            animation->setDuration(250*appearBallTab[i]);
            animation->setStartValue(ball->scenePos());
            animation->setEndValue(QPointF(ball->scenePos().rx(),
                                           ball->scenePos().ry() + (RKULKI*2.0+ODLKULKI) * appearBallTab[i]));
            animationGroup->addAnimation(animation);
            eventsMV.push_back(qMakePair(ball,MOVE_BALL_EVENT));
        }
        appearBallTab[i]=0;
    }
}

void DiagramScene::updateStatusBar()
{
    char str[30];
    std::sprintf(str,"Earned points: %d", thisTurnAddPoints * thisTurnTimesPoints);
    windowStatusBar->setText(QString(str));
}

void DiagramScene::updateBalls()
{
    Ball *ball;
    QList<QGraphicsItem *> list = this->items();
    for(QList<QGraphicsItem *>::iterator it=list.begin(); it!=list.end(); it++) {
        ball = dynamic_cast<Ball*>(*it);
        if(ball==NULL) continue;
        ball->updateAfterMove();
    }
}

void DiagramScene::updateMoveEverything()
{
    Ball *ball;
    QList<QGraphicsItem *> list = this->items();
    for(QList<QGraphicsItem *>::iterator it=list.begin(); it!=list.end(); it++) {
        ball = dynamic_cast<Ball*>(*it);
        if(ball==NULL) continue;
        eventsMV.push_back(qMakePair(ball,MOVE_BALL_EVENT));
    }
    nextTurn();
}

void DiagramScene::updatePlayers() {
    activePlayer->addPoints(thisTurnAddPoints * thisTurnTimesPoints);
    activePlayer->setEnabled(false);
    disactivePlayer->setEnabled(true);
    Player *temp = activePlayer;
    activePlayer = disactivePlayer;
    disactivePlayer = temp;
}

void DiagramScene::nextAction()
{
    animationGroup->clear();
    if(eventsMV.size()+eventsF.size()==0) {
        updateStatusBar();
        updateBalls();
        updatePlayers();
        if(activePlayer->returnType()==Player::COMPUTER) makeComputerMove();
        return;
    }
    for(; eventsMV.size(); eventsMV.pop_front()) {
        if(eventsMV.front().second==MOVE_BALL_EVENT) moveBallEvent(eventsMV.front().first);
        else if(eventsMV.front().second==VANISH_BALL_EVENT) vanishBallEvent(eventsMV.front().first);
    }
    for(QVector<Ball*>::iterator it=removedBalls.begin(); it!=removedBalls.end(); it++) {
        delete (*it);
    }
    removedBalls.clear();
    for(; eventsF.size(); eventsF.pop_front()) {
        fallBallEvent(eventsF.front().first);
    }
    appearBallEvent();
    animationGroup->start();
}

void DiagramScene::nextTurn()
{
    qDebug() << "jest NextTurn()";
    thisTurnPoints=0;
    thisTurnAddPoints=0;
    thisTurnTimesPoints=1;
    nextAction();
}

void DiagramScene::createPixmaps()
{
    pixmaps.push_back(QPixmap("images/redball.gif"));
    pixmaps.push_back(QPixmap("images/greenball.gif"));
    pixmaps.push_back(QPixmap("images/blueball.gif"));
    pixmaps.push_back(QPixmap("images/yellowball.gif"));
    pixmaps.push_back(QPixmap("images/magentaball.gif"));
    pixmaps.push_back(QPixmap("images/cyanball.gif"));
    pixmaps.push_back(QPixmap("images/greyball.jpg"));
}

int DiagramScene::numberOfTypes = 5;
int DiagramScene::maximumSizeOfDiagramScene = 13;
QPixmap *BallBonus::bonusPixmap;
QPixmap *BallSkull::skullPixmap;
QPixmap *BallClepsydra::pixmaps[6];
int BallClepsydra::points[6]={0,5,10,15,20,25};

