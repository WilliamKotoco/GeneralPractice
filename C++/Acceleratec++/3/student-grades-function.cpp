#include<iomanip>
#include<iostream>
#include<ios>
#include<string>
#include<vector>
#include<algorithm>
float homework_sum();
float calcular_media(float, float, float);
int main()
{
    //
    using std::cin;
    using std::cout;

    std::string nome;
    float nota1, nota2, media_tarefas;
    cout<< "Digite seu nome: ";
    cin >> nome;
    cout << "Digite suas duas notas: ";
    cin >> nota1 >> nota2;
    
    media_tarefas = homework_sum();

    cout<< "Olá, " << nome << " sua média é de: " << std::setprecision(3) << calcular_media(nota1,nota2,media_tarefas);

    return 0;
}
float homework_sum()
{
    std::vector<double> notas;
    double nota;
    int mid, size;
    std::cout << "Digite as notas das tarefas, pare com ctrl-d";
    while (std::cin >> nota)
        notas.push_back(nota);
    size = notas.size();
    mid = size/2;
    sort(notas.begin(), notas.end());
    return size % 2 == 0 ? (notas[mid] + notas[mid-1])/2 : notas[mid];

}   
float calcular_media(float nota1, float nota2, float media_terefas)
{
   return   0.2*nota1 + 0.4*nota2 + 0.4 * media_terefas; 
}