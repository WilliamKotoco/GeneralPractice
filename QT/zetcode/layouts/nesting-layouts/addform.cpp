#include "addform.h"
#include <QGridLayout>
#include <QLabel>
#include<QPushButton>
#include <QLineEdit>
addForm::addForm(QWidget *parent) : QWidget(parent)
{
    auto *inputLabel = new QLabel("Item: ", this);
    inputLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    auto *addBtn = new QPushButton("ok", this);

    lineEdit = new QLineEdit(this);

    auto *grid = new QGridLayout();
    grid->addWidget(inputLabel, 0, 0);
    grid->addWidget(lineEdit, 0, 1);
    grid->addWidget(addBtn, 0, 3);

    setLayout(grid);

    setParent(parent, Qt::Dialog);
    connect(addBtn, &QPushButton::clicked, this, &addForm::getItem);



}
void addForm::getItem()
{
    QString item =lineEdit->text();
    emit itemAdded(item);
    close();
}
