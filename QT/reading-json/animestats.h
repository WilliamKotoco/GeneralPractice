#ifndef ANIMESTATS_H
#define ANIMESTATS_H

#include<QString>
class AnimeStats
{
private:
    QString title;
    int year;
    int ep;

    QString mainTag;
public:
    AnimeStats(QString title, QString tag, int ep, int year);
    QString getTitle();
    int getYear();
    int getEp();
    QString getMainTag();
};

#endif // ANIMESTATS_H
