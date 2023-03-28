#include <iostream>
#include <string>

class Person
{
public:
    Person(std::string name, int age, double money) // criando construtor
    {
        this->name = name;
        this->age = age;
        this->money = money;
    }

    std::string getString()
    {
        return this->name;
    }
    int getAge()
    {
        return this->age;
    }
    double getMoney()
    {
        return this->money;
    }

private:
    std::string name;
    int age;
    double money;
};

int main()
{
    using namespace std;
    Person teste("Name", 10, 324.3);

    cout << "Info" << endl;
    cout << "Nome: " << teste.getString() << endl;
    cout << "Idade: " << teste.getAge() << endl;
    cout << "Grana: " << teste.getMoney() << endl;
}
