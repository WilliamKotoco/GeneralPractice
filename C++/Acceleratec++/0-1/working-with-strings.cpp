#include<iostream>
#include<string>
int main()
{
    std::cout << "Digite seu nome: " << std::endl;
    std::string name;
    std::cin >> name;


  // const não muda nada na compilação, mas fica mais legívels
    const std::string greetings = "Hello, " + name + " we're glad to see you!";

    // a linha abaixo constrói uma string de (X,Y) sendo X o tamanho e Y o char.
    const std::string spaces(greetings.size(), ' ');
    std::cout<< greetings << std::endl;
    std::cout<< "*" << spaces << "*" << std::endl;
    return 0;
}