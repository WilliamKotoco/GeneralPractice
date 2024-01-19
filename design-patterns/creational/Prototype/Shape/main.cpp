#include "Rectangle.hpp"

int main (int argc, char *argv[]) {
  Shape *r1 = new Rectangle(3,4,"blue",23,3);
  Shape *r2 = r1->clone();
  r1->print_info();
  r2->print_info();
  return 0;
}
