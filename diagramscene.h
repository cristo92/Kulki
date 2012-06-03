#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QtGui>
#include <ctime>
#include "ball.h"
#include "ballnormal.h"

const int RKULKI = 15;
const int ODLKULKI = 5;
class DiagramScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DiagramScene(QObject *parent = 0, qint32 n = 6, qint32 k = 7);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void swap(Ball *ellipse1, Ball *ellipse2);
    int n,k;
    
signals:
    
public slots:
    
private:
    void createColors();
    bool moving;
    QVector<QColor> colors;
    Ball *pastEllipse;
};

#endif // DIAGRAMSCENE_H
