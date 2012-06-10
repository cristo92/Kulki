#ifndef PLAYER_H
#define PLAYER_H

#include <QtGui>
#include <QWidget>

class Player : public QWidget
{
    Q_OBJECT
public:
    enum type {HUMAN,COMPUTER};
    explicit Player(QWidget *parent = 0, QString name="");
    ~Player(){}
    void addPoints(int points) {
        myPoints+=points;
        pointsLabel->setText(QString::number(myPoints));
    }
    void setName(QString name) {
        myName = name;
        playerNameLabel->setText(myName);
    }
    void newPoints() {
        myPoints = 0;
        pointsLabel->setText(QString::number(myPoints));
    }
    void setType(type w) {who=w;}
    type returnType() {return who;}

    QString myName;
    int myPoints;
    
signals:
    
public slots:
    
private:
    type who;
    QFrame *line;
    QFrame *line_2;
    QLabel *playerNameLabel;
    QLabel *pointsLabel;
    QVBoxLayout *layout;
    QSpacerItem *spacer;
};

#endif // PLAYER_H
