#ifndef ADDFORM_H
#define ADDFORM_H
#pragma once
#include<QWidget>
#include <QLabel>
#include<QLineEdit>
class addForm : public QWidget
{
    Q_OBJECT

public:
    addForm(QWidget *parent = nullptr);


    public slots:
        void getItem(); // pega o item que o usuário digitou no form e fecha a tela

   signals:
    void itemAdded(QString item);
private:
    QLineEdit *lineEdit;


};



#endif // ADDFORM_H
