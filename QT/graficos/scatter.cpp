#include "scatter.h"
#include<QtDataVisualization>
#include<Q3DTheme>

#include <QMessageBox>
#include<QFile>
Scatter::Scatter(QWidget *parent, QVector<int> *heights, QStringList *names)
    : QMainWindow{parent}
{
    using namespace QtDataVisualization;
    this->heights = *heights;
    this->names = *names;

    QVector<int> teste;
    for (int i = 0; i < heights->length(); i++)
    {
        teste.append(2*i+3);
    }

    Q3DScatter *scatter = new Q3DScatter();
    Q3DTheme *theme = new Q3DTheme();
    theme->setType(Q3DTheme::ThemeArmyBlue);
    scatter->addTheme(theme);
    this->setCentralWidget(QWidget::createWindowContainer(scatter));
    scatter->setFlags(scatter->flags() ^Qt::FramelessWindowHint);
    QScatter3DSeries *series = new QScatter3DSeries();
    QScatterDataArray *data = new QScatterDataArray;
    for (int i =0; i < heights->length()/2; i++)
    {
        QScatterDataItem *dataItem = new QScatterDataItem();
        dataItem->setX(this->heights[i]);
        dataItem->setY(teste[i]);
        data->append(*dataItem);
    }

    series->dataProxy()->resetArray(data);
    scatter->axisY()->setTitle("teste");
    scatter->addSeries(series);
    scatter->show();



}
