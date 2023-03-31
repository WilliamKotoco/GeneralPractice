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
   // void remove();
    void add(QListWidget *list , QHBoxLayout *);
   // void clear();
   // void edit();
};
#endif // MAINWINDOW_H
