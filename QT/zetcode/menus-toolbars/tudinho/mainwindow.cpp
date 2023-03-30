#include "mainwindow.h"
#include<QAction>
#include<QMenu>
#include<QIcon>
#include<QStatusBar>
#include<QTextEdit>
#include<QMenuBar>
#include<QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QPixmap newpix("new.png");
     QPixmap openpix("open.png");
     QPixmap quitpix("quit.png");

    // sem icon, não vou baixar icon

    auto *quit = new QAction("&Sair", this);
     QMenu *file = menuBar()->addMenu("&Opções");
     file->addAction(quit); //adicinando  a QActtion no menu QMenu

     quit->setShortcut(tr("CTRL+Q")); // autoexplicativo

     connect(quit, &QAction::triggered, qApp, &QApplication::quit); //criando as conexoes


     QToolBar *toolbar = addToolBar("tool bar");
      toolbar->addAction(QIcon(newpix), "Novo arquivo");
      toolbar->addAction(QIcon(openpix), "Abrir arquivo");

    QAction *quit2 = toolbar->addAction(QIcon(quitpix), "Fechar");

    connect(quit2, &QAction::triggered, qApp, &QApplication::quit);

      auto *texto = new QTextEdit(this); // adicionando a label textEdit
      setCentralWidget(texto); // no centro

      statusBar()->showMessage("STATUS BAR");




}


