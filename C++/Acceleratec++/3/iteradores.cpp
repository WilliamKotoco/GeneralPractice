#include<iostream>
#include<vector>
#include<cstdlib>
int main()
{

    using std::vector;
    vector<int> RandomNumbers;
    for (int i = 0; i < 10; i++)
    {
        RandomNumbers.push_back(rand() % 10);
    }

    // iterador constante, usar apenas para leitura
    for (vector<int>::const_iterator iter = RandomNumbers.begin(); iter != RandomNumbers.end(); iter++ )
    {
        std::cout << *iter <<" ";
    }

    std::cout<<std::endl;
    // usando iterador que permite mudança
 for (vector<int>::iterator iter = RandomNumbers.begin(); iter != RandomNumbers.end(); iter++ )
    {
        *iter *= rand()%100;
        std::cout << *iter <<" ";
    }



}