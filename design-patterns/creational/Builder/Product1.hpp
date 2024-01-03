#include<iostream>
#include <iterator>
#include <string>
#include <vector>
class Product1{
  public:
    std::vector<std::string> parts_;
    
    void listParts() const{
      std::cout << "Product parts: ";
      for (auto item : parts_)
        std::cout << item << " ";
      std::cout<< "\n \n";
    }

};
