#include<iostream>
#include<string>
int main()
{
    std::string name;
    std::cout << "Digite seu nome: ";
    getline(std::cin, name);

    std::cout << name << std::endl;

    return 0;
}
