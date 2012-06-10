#include "player.h"

Player::Player(QWidget *parent, QString myName) :
    QWidget(parent), myName(myName), who(HUMAN)
{
    myPoints = 0;
    line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line_2 = new QFrame(this);
    line_2->setFrameShape(QFrame::HLine);
    line_2->setFrameShadow(QFrame::Sunken);
    playerNameLabel = new QLabel(myName,this);
    pointsLabel = new QLabel(QString::number(0),this);
    spacer = new QSpacerItem(2, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout = new QVBoxLayout(this);
    layout->addWidget(line);
    layout->addWidget(playerNameLabel);
    layout->addWidget(pointsLabel);
    layout->addWidget(line_2);
    layout->addItem(spacer);
    this->setLayout(layout);
}
