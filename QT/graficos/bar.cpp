    #include "bar.h"
    #include<QWindow>
    #include<QtDataVisualization/QtDataVisualization>
    #include<QHBoxLayout>


Bar::Bar(QWidget *   parent) :
        QWidget(parent)
    {
    using namespace QtDataVisualization;
    Q3DBars bars;
    QBar3DSeries *series = new QBar3DSeries;
    QBarDataRow *row  = new QBarDataRow(5);
    for (int i =0; i < 5; i++)
    {
        (*row).append(2*i+3);
    }
    series-> dataProxy()->addRow(row);
    bars.addSeries(series);
    bars.show();




}


    Bar::~Bar()
    {
    }
