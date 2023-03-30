#include "mainwindow.h"
#include<QAction>
#include<QMenu>
#include<QMenuBar>
SimpleMenu::SimpleMenu(QWidget *parent)
    : QMainWindow(parent)
{
    auto *quit = new QAction("&Sair", this);
    QMenu *file = menuBar()->addMenu("&Menu sair");
    file->addAction(quit);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}


