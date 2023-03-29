#include<plus-minus.h>
#include <QGridLayout>
#include<QWidget>

PlusMinus::PlusMinus(QWidget *parent) : QWidget(parent)
{
    auto *plusButton = new QPushButton("+", this);
    auto *minusButton = new QPushButton("-", this);
    label = new QLabel("0", this);

    // criando o layout grid
    auto *grid = new QGridLayout(this);
    grid->addWidget(plusButton, 0, 1);
    grid->addWidget(minusButton, 0, 2);
    grid->addWidget(label, 2, 2);

    setLayout(grid);

    // conecta o signal clicked do botao da instancia para o slot do plusminus onplus
    connect(plusButton, &QPushButton::clicked, this, &PlusMinus::onPlus);
    // faz o mesmo para menos
    connect(minusButton, &QPushButton::clicked, this, &PlusMinus::onMinus);
}

void PlusMinus::onPlus()
{
    int val = label->text().toInt();
    label->setText(QString::number(++val));
}
void PlusMinus::onMinus()
{
    int val = label->text().toInt();
    label->setText(QString::number(--val));
}
