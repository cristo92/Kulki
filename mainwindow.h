#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui>
#include "diagramscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createActions();
    void createMenuBar();

private:
    QMenu *fileMenu;
    QAction *newFileAction;
    QAction *openFileAction;

    DiagramScene *scene;
    QGraphicsView *view;

    QLabel *statusBarText;
};

#endif // MAINWINDOW_H
