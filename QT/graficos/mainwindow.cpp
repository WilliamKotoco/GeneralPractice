#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bar.h"
#include "scatter.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// todo: open on the main window and just pass to other classes.

    QFile file(":/biostats.csv");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox fail;
        fail.setText("file doesn't exist");
        fail.exec();
        this->close();
    }
    else
    {
        QVector<int> heights;
        QStringList names;
        QTextStream in(&file);

        while (! in.atEnd()) // thereads the file lmao
        {
            QString line = in.readLine();
            QStringList fields = line.split(","); // separates the fields in a list.
            heights.append(fields[3].toInt());
            names.append(fields[0]);

        }

        file.close();


        //lambda function allows to pass parameters to slots (?)
        connect(ui->BarButton, &QPushButton::clicked, this, [=]() {
            on_pushButton_2_clicked(heights, names);
        });

        connect(ui->scatter, &QPushButton::clicked, this, [=](){
            on_scatter_clicked(heights, names);
        });

}

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked(QVector<int> heights, QStringList names)
{
    Bar *bar = new Bar(nullptr, &heights, &names);
    bar->setFixedSize(1200,900);
    bar->show();
}


void MainWindow::on_scatter_clicked(QVector<int> heights, QStringList names)
{
    Scatter *scatter = new Scatter(nullptr, &heights, &names);
    scatter->setFixedSize(1200, 900);
    scatter->show();
}



