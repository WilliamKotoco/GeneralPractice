#include "mainwindow.h"
#include <QVBoxLayout>
#include<QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *centralWidget = new QWidget(this); // criando um widget central
      setCentralWidget(centralWidget);
    auto *vbox = new QVBoxLayout(centralWidget); // criando o layout
    vbox->setSpacing(1); // espaço entre os widget
    QLabel *titulo = new QLabel(this);
    titulo->setText("TOP 4 MELHORES MOMENTOS RESIDENT EVIL 4 REMAKE");

    QLabel *primeiro = new  QLabel(this);
    primeiro->setText("1- WESKER APARECENDO ");
    QLabel *segundo = new QLabel(this);
    segundo->setText("2 - TUTORIAL DE SPRAY");
    QLabel *terceiro = new QLabel(this);
    terceiro-> setText("3- GRANADA DE ATORDOAMENTO (NÃO É FLASH)");
    QLabel *quarto = new QLabel(this);
    quarto->setText("4- GAMEPLAY COM A ASHLEY");
    centralWidget->setFixedSize(500, 200);

    vbox->addWidget(titulo);
    vbox->addWidget(primeiro);
    vbox->addWidget(segundo);
    vbox->addWidget(terceiro);
    vbox->addWidget(quarto);



}


