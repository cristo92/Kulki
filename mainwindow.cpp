#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenuBar();
    Ball::createPixmaps();

    scene = new DiagramScene(this);
    view = new QGraphicsView(scene);


    QHBoxLayout *layout = new QHBoxLayout(this);

    QWidget *widget = new QWidget(this);
    view->setMaximumHeight(7*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    view->setMaximumWidth(7*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    view->setMinimumHeight(7*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    view->setMinimumWidth(7*(RKULKI*2+ODLKULKI)+ODLKULKI*3);
    layout->addWidget(view);
    widget->setLayout(layout);

    setCentralWidget(widget);


    statusBarText = new QLabel(this);
    statusBarText->setText("New game");
    statusBar()->addWidget(statusBarText);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::createActions()
{
    newFileAction = new QAction("New", this);
    newFileAction->setShortcut(QKeySequence::New);

    openFileAction = new QAction("Open", this);
    openFileAction->setShortcut(QKeySequence::Open);
}

void MainWindow::createMenuBar()
{
    fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(openFileAction);
}
