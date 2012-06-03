#ifndef BALL_H
#define BALL_H

#include <QtGui>

class Ball : public QGraphicsEllipseItem
{
public:
    explicit Ball(qreal x, qreal y, qreal w, qreal h, int myColor, QGraphicsScene *scene=0,
                  const QPen & pen = QPen(), const QBrush & brush = QBrush());
   /* void darken() {qDebug() << "kurwa darrken";
        this->setBrush(QBrush(Qt::black));
                  this->update();}*/
    //void darken() {this->setBrush(QBrush(colors[myColor+7]));}
    void darken() {this->setBrush(QBrush(this->brush().color().darker(200)));
                   qDebug() << "is valid " << this->brush().color().darker(200).isValid();}
    void lighten() {this->setBrush(QBrush(this->brush().color().lighter(200)));}

    virtual bool isColor(QColor color) = 0;
    virtual int sumPoints() = 0;
    virtual int timesPoints() = 0;
    virtual void updateAfterMove() = 0;

protected:
    static QColor colors[14];
    int myColor;
};

#endif // BALL_H
