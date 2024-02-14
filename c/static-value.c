#include <stdio.h>


void test()
{
  int a = 1;
  static int b = 0;

  printf("%d %d \n", ++a, ++b);
}

int main(int argc, char *argv[])
{
  test();
  test();
  test();

  return 0;
}
