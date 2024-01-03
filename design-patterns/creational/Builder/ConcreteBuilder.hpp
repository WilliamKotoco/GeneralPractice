#include "Builder.hpp"
#include "Product1.hpp"
class ConcreteBuilder1 : public Builder{
  private:
    Product1 *product;


  public:
    ConcreteBuilder1(){
      this->product = new Product1();
    }

    void producePartA() const override{
      this->product->parts_.push_back("PART A");
    }

    void producePartB() const override{
      this->product->parts_.push_back("PART B");
    }

    void producePartC() const override{
      this->product->parts_.push_back("PART C");
    }
    void reset(){
      this->product = new Product1();
    }

    Product1 *getProduct(){
      Product1 *result = this->product;
      this->reset();
      return result;
    }
}; 
