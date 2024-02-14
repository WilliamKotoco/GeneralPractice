#include <iostream>


void print_test(int a = 100)
{
  std::cout<< a << "\n";
}

int main (int argc, char *argv[]) {
  

  print_test(3);
  print_test();
  return 0;
}
