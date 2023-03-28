#include <algorithm>
#include <QList>
#include <QTextStream>

int main()
{
    int i;
    QTextStream out(stdout);

    QList<QString> frutas = {"banana", "maca", "aleardo", "uva"}; //QString é a string

    for (QList<QString>::const_iterator iter = frutas.constBegin(); iter != frutas.constEnd() ; iter++)
        out << *iter << Qt::endl;

    frutas << "pera" << "sample text";

    out << "                     "<<Qt::endl;

    std::sort(frutas.begin(), frutas.end());
    // outra maneira de printar
    for (QString fruta: frutas)
        out << fruta << " ";


        return 0;
    
}