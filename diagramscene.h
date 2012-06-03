#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QtGui>
#include <ctime>
#include "ball.h"
#include "ballnormal.h"

class DiagramScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum {NOTHING_CHOSEN,FIRST_BALL_CHOSEN,SECOND_BALL_CHOSEN};
    explicit DiagramScene(QObject *parent = 0, qint32 n = 7, qint32 k = 7);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void swap(Ball *ellipse1, Ball *ellipse2);
    int n,k;
    
signals:

public slots:

private:
    void createPixmaps();
    int sceneMode;
    QVector<QPixmap> pixmaps;
    Ball *firstEllipse, *secondEllipse;
};
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};


#endif // DIAGRAMSCENE_H
