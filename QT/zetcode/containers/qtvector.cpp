/*
#include <QVector>
#include <QTextStream>
#include<QApplication>
int main(void)
{
    QTextStream out(stdout);
    QVector<int> vals = {1,2,3,4};

    out << "Tamanho "<< vals.size()<< Qt::endl;

    out << "Primeiero: " << vals.first() << Qt::endl;
    out <<"Last: "<<vals.last() <<  Qt::endl;

    vals.append(19);
    vals.prepend(0);


    out <<"Elementos: "<< Qt::endl;

    for (int val: vals){
        out << val << " ";
    }
    return 0;
}
*/