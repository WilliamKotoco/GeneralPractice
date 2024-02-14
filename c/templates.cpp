#include <iostream>
#include <ostream>

template<typename T> 
T myMax(T a, T b){
  if (a > b)
    return a;
  return b;
}

template<>
std::string myMax(std::string a, std::string b)
{
  std::cout << "if you want to handle differently a data type/class";
  return "none";
}
int main (int argc, char *argv[]) {
  
  std::cout << myMax(5, 10) << std::endl;
  std::cout << myMax('a', 'z') << std::endl; 
  std::cout << myMax(5.2, 10.532) << std::endl;


/// sometimes the CE cannot guess the type, so you have to explicit it:
  std::cout << myMax<double>(1, 930.35)<< std::endl;
 
  std::string a = "test1";
  std::string b = "test2";
  std::cout << myMax(a, b);
  return 0;
}
