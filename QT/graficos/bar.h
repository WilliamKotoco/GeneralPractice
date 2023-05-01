#ifndef BAR_H
#define BAR_H

#include <QMainWindow>
#include<QVector>

class Bar : public QMainWindow
{
    Q_OBJECT
public:
    explicit Bar(QWidget *parent = nullptr, QVector<int> *heights = nullptr, QStringList *names = nullptr);
    QVector<int> heights;
    QStringList names;

signals:

};

#endif // BAR_H
