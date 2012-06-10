#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Ball::createPixmaps();
    BallKameleon::kameleonPixmap = new QPixmap("images/kameleon.gif");
    BallJoker::jokerChosenPixmap = new QPixmap("images/jokerBallChosen.gif");
    BallJoker::jokerPixmap = new QPixmap("images/jokerBall.gif");
    BallSkull::skullPixmap = new QPixmap("images/skull.gif");
    BallBonus::bonusPixmap = new QPixmap("images/bonusBall.gif");
    BallClepsydra::pixmaps[5] = new QPixmap("images/klepsydra25.gif");
    BallClepsydra::pixmaps[4] = new QPixmap("images/klepsydra20.gif");
    BallClepsydra::pixmaps[3] = new QPixmap("images/klepsydra15.gif");
    BallClepsydra::pixmaps[2] = new QPixmap("images/klepsydra10.gif");
    BallClepsydra::pixmaps[1] = new QPixmap("images/klepsydra05.gif");
    BallClepsydra::pixmaps[0] = new QPixmap("images/klepsydra.gif");
    newGameDialog = new NewGameDialog(this);
    connect(newGameDialog,SIGNAL(accepted()),this,SLOT(newGame()));
    createActions();
    createMenuBar();
    aloneMode=false;

    statusBarText = new QLabel(this);
    statusBarText->setText("New game");
    statusBar()->addWidget(statusBarText);

    for(int i=0; i<5; i++) pcBallsTab[i]=1;
    scene = new DiagramScene(this,statusBarText,7,6);
    view = new QGraphicsView(scene);
    player1 = new Player(this,"Player 1");
    player1->setMinimumHeight(RKULKI*4);
    player1->setMinimumWidth(RKULKI*4);
    player1->setEnabled(true);
    scene->activePlayer = player1;
    player2 = new Player(this,"Player 2");
    player2->setMinimumHeight(RKULKI*4);
    player2->setMinimumWidth(RKULKI*4);
    player2->setEnabled(false);
    scene->disactivePlayer = player2;

    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *layout2 = new QVBoxLayout(this);
    layout2->addWidget(player1);
    layout2->addWidget(player2);

    QWidget *widget = new QWidget(this);
    view->setMinimumHeight(7*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    view->setMinimumWidth(7*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    layout->addWidget(view);
    layout->addLayout(layout2);
    widget->setLayout(layout);

    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::createActions()
{
    newGameAction = new QAction(tr("New Game"),this);
    connect(newGameAction,SIGNAL(triggered()),newGameDialog,SLOT(exec()));

    saveResultAction = new QAction(tr("Save Result"), this);
    connect(saveResultAction,SIGNAL(triggered()),this,SLOT(saveResult()));

    showResultAction = new QAction(tr("Show Result"), this);
    connect(showResultAction,SIGNAL(triggered()),this,SLOT(showResult()));
}

void MainWindow::createMenuBar()
{
    gameMenu = menuBar()->addMenu("Game");
    gameMenu->addAction(newGameAction);

    resultMenu = menuBar()->addMenu("Results");
    resultMenu->addAction(saveResultAction);
    resultMenu->addAction(showResultAction);
}

void MainWindow::newGame()
{
    qDebug() << "New Game";
    player1->newPoints();
    player2->newPoints();
    player1->setName(newGameDialog->returnPlayer1Name());
    player2->setName(newGameDialog->returnPlayer2Name());
    player1->setType(newGameDialog->returnPlayer1Type());
    player2->setType(newGameDialog->returnPlayer2Type());

    size = newGameDialog->returnSize();
    numberOfColors = newGameDialog->returnColors();
    aloneMode = newGameDialog->isAloneMode();
    for(int i=0; i<5; i++) pcBallsTab[i] = newGameDialog->isBallType(i);
    pcBonusBalls = newGameDialog->returnPercentBonusBalls();

    view->setMinimumHeight(size*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    view->setMinimumWidth(size*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    scene->reConstruct(size,numberOfColors,aloneMode,pcBonusBalls,pcBallsTab);
    //this->update();

    scene->activePlayer=player1;
    scene->disactivePlayer=player2;
    if(aloneMode) scene->disactivePlayer=player1;
    qDebug() << "Player1 Type: " << player1->returnType() << " Player2 Type: " << player2->returnType();
    if(scene->activePlayer->returnType()==Player::COMPUTER) {
        scene->thisTurnPoints=0;
        scene->thisTurnAddPoints=0;
        scene->thisTurnTimesPoints=1;
        scene->updateStatusBar();
        scene->updateBalls();
        scene->updatePlayers();
        scene->makeComputerMove();
    }
}

void MainWindow::saveResult() {
    if(!aloneMode) {
        QMessageBox::warning(this,"Alone mode","Saving result is possible only with Alone Mode");
        return;
    }
    QFile file("results.txt");
    file.open(QIODevice::Append);
    QTextStream out(&file);
    out << scene->activePlayer->myName;
    out << " ";
    out << QString::number(scene->activePlayer->myPoints) << "\n";
    QMessageBox::information(this,"Well Done","Result was succesfully saved");
}

void MainWindow::showResult() {
    QFile file("results.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString str;
    QString wholeStr;
    while(!in.atEnd()) {in >> str; wholeStr += str + "\n";}
    QMessageBox(QMessageBox::NoIcon,"Results",wholeStr,QMessageBox::NoButton,this).exec();
}
