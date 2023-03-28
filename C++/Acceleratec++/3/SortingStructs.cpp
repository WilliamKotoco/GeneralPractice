 #include<iostream>
#include<string>
#include<iomanip>
#include<ios>
#include<vector>
#include<algorithm>
 struct StudentGrade
 {
    std::string name;
    float finalgrade;

 };
bool compare(StudentGrade s1, StudentGrade s2);
int main()
{
int i;
std::string name;
float grade;

StudentGrade students[5]; 
std::vector<StudentGrade> studentsVector;
for (int i = 0 ; i < 5; i++)
{
    std::cout <<"Digite o nome: ";
    std::cin >> name;
    students[i].name = name;
    std::cout<<"Digite a nota : ";
    std::cin >> grade;
    students[i].finalgrade = grade;

    studentsVector.push_back(students[i]);
}
    sort(studentsVector.begin(), studentsVector.end(), compare);
    for (int i = 0 ; i < studentsVector.size() ; i++)
        std::cout << studentsVector[i].name << " " << studentsVector[i].finalgrade << std::endl;
}
bool compare(StudentGrade s1, StudentGrade s2)
{
    return s1.name < s2.name;
}
