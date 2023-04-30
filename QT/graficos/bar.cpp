#include "bar.h"
#include<QtDataVisualization>
 #include <QMessageBox>
#include<QFile>
Bar::Bar(QWidget *parent)
    : QMainWindow{parent}
{
    /*
     * todo: return to initial screen if the file doesn't open.
     *
     *
     * todo: show the names of each height
     */
    using namespace QtDataVisualization;
    QFile file(":/biostats.csv");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox fail;
        fail.setText("file doesn't exist");
        fail.exec();
        this->close();
    }
    else
    {
        QVector<int> heights;
        QStringList names;
        QTextStream in(&file);

        while (! in.atEnd()) // reads the file lmao
        {
            QString line = in.readLine();
            QStringList fields = line.split(","); // separates the fields in a list.
            heights.append(fields[3].toInt());
            names.append(fields[0]);

        }

        file.close();


    Q3DBars *bars = new Q3DBars();

    this->setCentralWidget(QWidget::createWindowContainer(bars));
    bars->setBarThickness(1.0);
    bars->setFlags(bars->flags() ^ Qt::FramelessWindowHint);
   bars->rowAxis()->setRange(0, heights.length());
    bars->columnAxis()->setRange(0, heights.length());
   bars->columnAxis()->setLabels(names);
    bars->setTitle("Height in foot ");
    QBar3DSeries *series = new QBar3DSeries;
    QBarDataRow *data = new QBarDataRow;

    for(int i =0; i < heights.length(); i++)
    {
            (*data).append(heights[i]);
    }
    series->dataProxy()->addRow(data);
    bars->addSeries(series);
    bars->show();
    }
}
