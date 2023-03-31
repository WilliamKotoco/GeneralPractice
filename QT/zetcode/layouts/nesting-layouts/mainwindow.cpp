#include "mainwindow.h"
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    auto *vbox = new QVBoxLayout(); // sem o this porque não é pra ser aplicado nesse
    auto *hbox = new QHBoxLayout(this);

    auto *list = new QListWidget(this);
    list->addItem("Tomate");
    list->addItem("Manteiga");
    list->addItem("Café");
    list->addItem("Churrasco");

    auto *addbtn = new QPushButton("Add", this);
    auto *editbtn = new QPushButton("Edit", this);
    auto *removebtn = new QPushButton("Remove", this);
    auto *clearbtn = new QPushButton("Clear", this);

    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(addbtn);
    vbox->addWidget(editbtn);
    vbox->addWidget(removebtn);
    vbox->addWidget(clearbtn);
    vbox->addStretch(1);


    hbox->addWidget(list);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

     setLayout(hbox);

    connect(addbtn, &QPushButton::clicked, this, [=] ()
    {
        MainWindow::add(list, hbox);
    });
   // connect(remove, &QPushButton::clicked, this, &MainWindow::remove);
    //connect(edit, &QPushButton::clicked, this, &MainWindow::edit);
    //connect(clear, &QPushButton::clicked, this, &MainWindow::clear);


}

void MainWindow::add(QListWidget *list, QHBoxLayout *hbox)
{
hbox->removeWidget(list);
list->addItem("sample text");
hbox->addWidget(list);

}
