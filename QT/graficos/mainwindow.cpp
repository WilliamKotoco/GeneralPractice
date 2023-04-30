#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    Bar *bar = new Bar();
    bar->setFixedSize(1000,1000);
    bar->show();
}

