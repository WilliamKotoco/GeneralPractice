#include <cstdio>
class A{
  public:
    static int number;
};

int A::number = 0;
void increase(){
  A::number += 199;
}

int main (int argc, char *argv[]) {
  
  A a;
  std::printf("%d \n", a.number);
  increase();

  A b;
  std::printf("%d \n", b.number);
  return 0;
}
