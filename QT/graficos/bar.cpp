   #include "bar.h"
#include<QtDataVisualization>
#include<Q3DTheme>
 #include <QMessageBox>
#include<QFile>
Bar::Bar(QWidget *parent, QVector<int> *heights, QStringList *names)
    : QMainWindow{parent}
{
    /*
     * todo: return to initial screen if the file doesn't open.
     *
     *
     * todo: show the names of each height
     */
    using namespace QtDataVisualization;
    this->heights = *heights;
    this->names = *names;



    Q3DBars *bars = new Q3DBars();
        Q3DTheme *theme = new Q3DTheme();
    theme->setType(Q3DTheme::ThemeArmyBlue);
        bars->setActiveTheme(theme);
    this->setCentralWidget(QWidget::createWindowContainer(bars));
    bars->setBarThickness(1.0);
    bars->setFlags(bars->flags() ^ Qt::FramelessWindowHint);
    bars->rowAxis()->setRange(0, this->heights.length());
    bars->columnAxis()->setRange(0, this->heights.length());

    bars->columnAxis()->setLabels(this->names);
    bars->setTitle("Height in foot ");
    QBar3DSeries *series = new QBar3DSeries;
    QBarDataRow *data = new QBarDataRow;

    for(int i =0; i < this->heights.length(); i++)
    {
        (*data).append(this->heights[i]);
    }
    series->dataProxy()->addRow(data);
    bars->addSeries(series);
    bars->show();
    }

