#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
bool conditionToRemove(int n1);
int main()
{
    using std::vector;
    vector<int> RandomNumbers;
    for (int i = 0; i < 10; i++)
    {
        RandomNumbers.push_back(rand() % 200);
    }

    for (vector<int>::const_iterator iter = RandomNumbers.begin(); iter != RandomNumbers.end(); iter++)
        std::cout << *iter << " ";
    std::remove_if(RandomNumbers.begin(), RandomNumbers.end(), conditionToRemove);

    std::cout << std::endl;
    for (vector<int>::const_iterator iter = RandomNumbers.begin(); iter != RandomNumbers.end(); iter++)
        std::cout << *iter << " ";

    std::cout << "O remove_if não remove, ele joga o elemento para trás" << std::endl;

    // para efetivamente remover:
    RandomNumbers.erase(std::remove_if(RandomNumbers.begin(), RandomNumbers.end(), conditionToRemove), RandomNumbers.end());
    std::cout << std::endl;
    for (vector<int>::const_iterator iter = RandomNumbers.begin(); iter != RandomNumbers.end(); iter++)
        std::cout << *iter << " ";
}
bool conditionToRemove(int n1)
{
    return n1 < 100;
}