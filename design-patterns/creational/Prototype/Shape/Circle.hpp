#include "Shape.hpp"
#include <cstdio>

class Circle : public Shape{
  protected:
    int radius;

  public:
    Circle();

    Circle(float x, float y, std::string color, int radius) : Shape(x,y,color){
     this->radius = radius;
    }
                            
    Shape *clone()  const override{
      return new Circle(*this);
    }

    void print_info() const override
    {
      std::cout << "X: " << x << std::endl;
      std::cout << "Y: " << y << std::endl;
      std::cout << "color: " << color << std::endl;
      std::cout << "radius: " << radius << std::endl;
    }
};
