#include "diagramscene.h"

DiagramScene::DiagramScene(QObject *parent, qint32 n, qint32 k) :
    QGraphicsScene(parent), n(n), k(k)
{
    createColors();
    moving=false;
    pastEllipse=NULL;
    this->setSceneRect(0,0,n*(RKULKI*2+ODLKULKI),n*(RKULKI*2+ODLKULKI));
    double X=ODLKULKI;
    double Y=ODLKULKI;
    int nrOfColor;
    for(int i=0; i<n; i++, X+=RKULKI*2+ODLKULKI) {
        Y=ODLKULKI;
        for(int j=0; j<n; j++, Y+=RKULKI*2+ODLKULKI) {
            nrOfColor=rand()%k;
            this->addItem(new BallNormal(X,Y,RKULKI*2,RKULKI*2,nrOfColor,nrOfColor+1,this,QPen(),QBrush(colors[nrOfColor])));//->setActive(true);
        }
    }
}

void DiagramScene::createColors()
{
    colors.push_back(Qt::red);
    colors.push_back(Qt::green);
    colors.push_back(Qt::blue);
    colors.push_back(Qt::yellow);
    colors.push_back(Qt::magenta);
    colors.push_back(Qt::cyan);
    colors.push_back(Qt::gray);
    colors.push_back(Qt::darkRed);
    colors.push_back(Qt::darkGreen);
    colors.push_back(Qt::darkBlue);
    colors.push_back(Qt::darkYellow);
    colors.push_back(Qt::darkMagenta);
    colors.push_back(Qt::darkCyan);
    colors.push_back(Qt::darkGray);
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Ball *ellipse = dynamic_cast<Ball*>(this->itemAt(event->scenePos()));
    if(ellipse==NULL) {
        moving=false;
        if(pastEllipse!=NULL) {
            pastEllipse->lighten();
            this->update(pastEllipse->scenePos().rx(),pastEllipse->scenePos().ry(),RKULKI,RKULKI);
        }
        qDebug() << "There is no ball";
        return;
    }
    update(ellipse->scenePos().x(),ellipse->scenePos().y(),RKULKI,RKULKI);
    if(moving) {
        pastEllipse->lighten();
        this->update(pastEllipse->scenePos().rx(),pastEllipse->scenePos().ry(),RKULKI,RKULKI);
        swap(ellipse,pastEllipse);
        moving=false;
    }
    else {
        qDebug() << "darking";
        pastEllipse=ellipse;
        pastEllipse->darken();
        //pastEllipse->setBrush(QBrush(Qt::black));
        this->update();//pastEllipse->scenePos().rx(),pastEllipse->scenePos().ry(),RKULKI,RKULKI);
        moving=true;
    }
}

void DiagramScene::swap(Ball *ellipse1, Ball *ellipse2)
{
    qDebug() << "swapuje" << ellipse1->scenePos().x() << "," << ellipse1->scenePos().y() << " " << ellipse2->scenePos().x()
             << "," << ellipse2->scenePos().y();
    QBrush temp = ellipse1->brush();
    ellipse1->setBrush(ellipse2->brush());
    ellipse2->setBrush(temp);
    this->update(ellipse1->scenePos().rx(),ellipse1->scenePos().ry(),RKULKI,RKULKI);
    this->update(ellipse2->scenePos().rx(),ellipse2->scenePos().ry(),RKULKI,RKULKI);
}
