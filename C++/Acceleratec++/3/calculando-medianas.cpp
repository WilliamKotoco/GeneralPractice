#include<iostream>
#include<ios>
#include<iomanip>
#include<algorithm>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
int main()
{
    double grade;
    std::vector<double> grades; // vector são arrays dinamicos, igual a ArrayList de java

    
    // guardar o tamanho possível de um vector double, fazendo já todas as verificações

    cout<<"Digite as notas: "<<endl;
    while(cin>>grade)
        grades.push_back(grade); // adiciona no final do array dinamico
    
    std::vector<double>::size_type size = grades.size();

    sort(grades.begin(), grades.end());
    int mid = size/2;
    double median = size % 2 == 0 ? (grades[mid] + grades[mid-1])/2 : grades[mid];

    cout << "A mediana é: " << median;





}