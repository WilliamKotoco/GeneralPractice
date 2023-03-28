#include<iostream>
#include<string>
#include<string>
#include<ios>
#include<map>


int main()
{
    
    std::string s;
    std::map<std::string,int> counters;
    
    // trackear o quanto cada palavra aparece
    while(std::cin >> s)
        ++counters[s];
    for (std::map<std::string,int>::const_iterator iter =  counters.begin(); iter != counters.end(); iter++ )
        std::cout << iter->first << " " << iter->second <<std::endl;
}