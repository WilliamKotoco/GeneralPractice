#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 class  Student
{
public:
    double getFinalGrade()
    {
        using namespace std;
        double x;
        vector<double> hw_grades;
        cout << "Digite o midterm" << endl;
        cin >> this->midterm;
        cout << "Digite a nota da final: ";
        cin >> this->final;
        cout << "Digite as notas das tarefas, cancele com ctrl-d";
        while (cin >> x)
        {
            hw_grades.push_back(x);
        }
        sort(hw_grades.begin(), hw_grades.end());

        return (midterm + final + mediana(hw_grades)) / 3;
    }

    double mediana(std::vector<double> array)
    {
        int mid;
        std::vector<double>::size_type size = array.size();
        mid = size / 2;
        return size % 2 == 0 ? (array[mid] + array[mid - 1]) / 2 : array[mid];
    }
    std::string nome;

private:
    double midterm, final;
    std::vector<double> hw_grades;
};

int main()
{
    Student test;
    std::cout << "Digite o nome: " << std::endl;
    std::cin >> test.nome;
    double result = test.getFinalGrade();
    std::cout << "A nota final é: " << result;

    return 0;
}