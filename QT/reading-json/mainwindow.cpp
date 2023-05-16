#include "mainwindow.h"
#include <QFile>
#include<QTextStream>
#include<QJsonDocument>
#include <QVector3D>
#include<QJsonObject>
#include<QJsonArray>
#include <QtDataVisualization>
struct epPerGenre
{
    QString genre;
    int eps;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    {
    QVector<AnimeStats> animes = readData();
        QTextStream m(stdout);
    Q3DBars *bars= new Q3DBars();
    bars->setFlags(bars->flags() ^ Qt::FramelessWindowHint);
    this->setCentralWidget(QWidget::createWindowContainer(bars));

    }

QVector<AnimeStats> MainWindow::readData()
{
    QFile file(":/anime-offline-database.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        this->close();
    }
    else
    {
        /*
         * Converts the file in QByteArray. It's more efficient working
         * with binary data, and it allows QJsonDocument to analyse the file's content
          */
        QByteArray bytes = file.readAll();
        file.close();

        //        parse the json datas
        QJsonParseError error;
        // parses json to a JsonDocument
        QJsonDocument document = QJsonDocument::fromJson(bytes, &error);
        if(error.error != QJsonParseError::NoError)
        {
            // handle error
        }
        QVector<AnimeStats> animes;
        QJsonObject data= document.object(); // the file has a object with json arrays
        QJsonArray dataArray = data.value("data").toArray(); // converts the object data (which have the stats) in an array

        for (auto jsonValue: dataArray)
        {
            QString title =jsonValue.toObject().value("title").toString();
            QString tag = jsonValue.toObject().value("tags").toArray().at(0).toString();
            int ep = jsonValue.toObject().value("episodes").toInt();
            QJsonObject animeSeason = jsonValue.toObject().value("animeSeason").toObject();
            int year = animeSeason.value("year").toInt();

            AnimeStats anime(title, tag, ep, year);
            animes.append(anime);

        }

        /*
         * in this point we already have all the data from json file stored in the
         * anime vector..
         * */
        return animes;


    }
    }


MainWindow::~MainWindow()
{
}

