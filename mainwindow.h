#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui>
#include "diagramscene.h"
#include "newgamedialog.h"
#include "player.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    enum ballNames {CAMELEON_BALL,JOKER_BALL,BONUS_BALL,SKULL_BALL,CLEPSYDRA_BALL};
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createActions();
    void createMenuBar();

    DiagramScene *scene;

public slots:
    void newGame();
    void saveResult();
    void showResult();


private:
    int size,numberOfColors;
    Player *player1,*player2;
    bool aloneMode;
    int pcBonusBalls;
    int pcBallsTab[5];

    QMenu *gameMenu;
    QMenu *resultMenu;
    QAction *newGameAction;
    QAction *saveResultAction;
    QAction *showResultAction;

    QGraphicsView *view;

    QLabel *statusBarText;

    NewGameDialog *newGameDialog;
};

#endif // MAINWINDOW_H
