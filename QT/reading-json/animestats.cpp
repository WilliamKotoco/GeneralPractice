#include "animestats.h"

AnimeStats::AnimeStats(QString title, QString tag, int ep, int year)
{
    this->title = title;
    this->mainTag = tag;
    this->ep = ep;
    this->year = year;
}
int AnimeStats::getYear()
{
    return this->year;
}
QString AnimeStats::getTitle()
{
    return this->title;
}
QString AnimeStats::getMainTag()
{
    return this->mainTag;
}
int AnimeStats::getEp()
{
    return this->ep;
}
