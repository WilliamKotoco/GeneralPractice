#include "mainwindow.h"

#include<QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    // site for getting more datasets: https://awesomeopensource.com/project/jdorfman/awesome-json-datasets
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    w.setFixedSize(900,500);
    return a.exec();
}
