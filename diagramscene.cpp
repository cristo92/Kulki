#include "diagramscene.h"

DiagramScene::DiagramScene(QObject *parent, qint32 n, qint32 k) :
    QGraphicsScene(parent), n(n), k(k)
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
    ellipse1->setPos(ellipse2->scenePos());
    ellipse2->setPos(temp);
    this->update(ellipse1->scenePos().rx(),ellipse1->scenePos().ry(),RKULKI,RKULKI);
    this->update(ellipse2->scenePos().rx(),ellipse2->scenePos().ry(),RKULKI,RKULKI);
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
