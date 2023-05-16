#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<animestats.h>
#include <QMainWindow>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector<AnimeStats>readData();

private:
};
#endif // MAINWINDOW_H
