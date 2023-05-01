#ifndef SCATTER_H
#define SCATTER_H

#include <QMainWindow>

class Scatter : public QMainWindow
{
    Q_OBJECT
public:
    Scatter(QWidget *parent = nullptr, QVector<int> *heights = nullptr, QStringList *names = nullptr);
    QVector<int> heights;
    QStringList names;
};

#endif // SCATTER_H
