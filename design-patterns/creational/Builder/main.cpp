#include "ConcreteBuilder.hpp"
#include "Director.hpp"
#include <iostream>


int main (int argc, char *argv[]) {
  
  ConcreteBuilder1 *concreteBuilder  = new ConcreteBuilder1();
  Director *director = new Director(concreteBuilder);

  Product1 *product = new Product1();

  std::cout << "MVP: \n";
  /// director receives a pointer to ConcreteBuilder, so it will change ConcreteBuilder
  director->createMVP();

  product = concreteBuilder->getProduct();

  product->listParts();

  delete product;

  std::cout << "Full product: \n";
  director->createFullProduct();
  product = concreteBuilder->getProduct();
  product->listParts();
  
  delete product;

  std::cout<<"Personalized product: \n";
  director->createCustom();
  product = concreteBuilder->getProduct();
  product->listParts();


  return 0;

}
