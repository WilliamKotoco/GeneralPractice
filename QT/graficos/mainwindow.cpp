#include "mainwindow.h"
#include "./ui_mainwindow.h"
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


void MainWindow::on_pushButton_3_clicked()
{
Bar *bar = new Bar(this);
bar->resize(700,700);
bar->show();


}

