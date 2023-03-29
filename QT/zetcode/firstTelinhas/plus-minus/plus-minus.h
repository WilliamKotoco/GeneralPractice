#pragma once
#include<QWidget>
#include<QApplication>
#include<QPushButton>
#include<QLabel>

class PlusMinus : public QWidget
{
    Q_OBJECT // vai usar signals and slots

    public:
        PlusMinus(QWidget *parent = nullptr);

    private slots:
    void onPlus();
    void onMinus();

    private:
    QLabel *label;
};

