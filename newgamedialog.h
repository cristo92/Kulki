#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <QtGui>
#include "player.h"
#include "diagramscene.h"
#include "ball.h"
#include "ballbonus.h"
#include "balljoker.h"
#include "ballkameleon.h"
#include "ballskull.h"

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT
    
public:
    enum ballNames {CAMELEON_BALL,JOKER_BALL,BONUS_BALL,SKULL_BALL,CLEPSYDRA_BALL};
    enum percentage {FEW=5,NORMAL=10,LOT=20,ENORMOUS=50};
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();
    int returnSize();
    int returnColors();
    int returnPercentBonusBalls();
    QString returnPlayer1Name();
    QString returnPlayer2Name();
    Player::type returnPlayer1Type();
    Player::type returnPlayer2Type();
    bool isBallType(int type);
    bool isAloneMode();


public slots:
    void myResize(bool bol);
    
private:
    Ui::NewGameDialog *ui;
    QSize hiddenSize;
};

#endif // NEWGAMEDIALOG_H
