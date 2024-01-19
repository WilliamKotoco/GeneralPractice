#include <string>
#include <iostream>
class Shape
{
  protected:
    float x;
    float y;
    std::string color;
  
  public:
    Shape();

    Shape(float x, float y, std::string color){
      this->x = x;
      this->y = y;
      this->color = color;

    }

    virtual Shape *clone() const = 0;

    virtual void print_info() const =0;
};
