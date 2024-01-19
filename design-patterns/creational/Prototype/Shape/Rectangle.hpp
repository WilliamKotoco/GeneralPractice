#include "Shape.hpp"

class Rectangle : public Shape{
  protected:
    float width;
    float height;

  public:
  Rectangle(float x, float y, std::string color, float width, float height) : Shape(x,y,color)
  {
    this->width = width;
    this->height = height;
  }

  Shape *clone() const override{
    return new Rectangle(*this);
  }

    void print_info() const override
    {
      std::cout << "X: " << x << std::endl;
      std::cout << "Y: " << y << std::endl;
      std::cout << "color: " << color << std::endl;
      std::cout << "width: " << width << std::endl;
      std::cout << "height: " << height << std::endl;
    }
};
