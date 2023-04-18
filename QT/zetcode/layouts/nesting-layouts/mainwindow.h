#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include<QWidget>
#include <QVBoxLayout>
#include<QListWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
//    void remove(QListWidget *list);
    void add(QListWidget *list);
    void addItemToList(QString item);

   // void clear();
   // void edit();

      private:
          QListWidget *listWidget;
};


#endif // MAINWINDOW_H
