#include<iomanip>
#include<iostream>
#include<ios>
#include<string>
#include<vector>
using namespace std; // importa tudo do STD

int main()
{
    string name;
    double p1, p2, grades = 0, sum = 0, count = 0;
    cout<<"Digite o nome: ";
    cin >> name;

    cout<<"Digite a nota da p1 e da p2: ";
    cin >> p1 >> p2;

    cout<<"Digite todas as notas das tarefas \n finalizando com ctrl-d"<<endl;
    
    while (cin >> grades)
    {
        ++count;
        sum += grades;
    }

    streamsize precision = cout.precision();
    cout << "Nota final: " << setprecision(3) << 0.2*p1 + 0.4*p2 + 0.4* sum/count << setprecision(precision) << endl;

    return 0; 
}