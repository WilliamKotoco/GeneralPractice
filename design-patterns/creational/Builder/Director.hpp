/// director is the responsible for creating specialized products
///
#include "Builder.hpp"

class Director{
  private:
    Builder *builder;

  public:

    Director(Builder *builder){
      this->builder = builder;
    }

    void createMVP(){
      this->builder->producePartA();
    }
    
    void createFullProduct(){
      this->builder->producePartA();
      this->builder->producePartB();
      this->builder->producePartC();
    }

    void createCustom(){
      this->builder->producePartC();
      this->builder->producePartB();
    }
};
