#include<stdio.h>
#include<stdlib.h>

void swap (const int * n1, const int *n2)
{
    int a = *n1;
    // here we are trying to change a read-only location, the reason of compiler error 
    *n1 = *n2;
    *n2 = a;
}

int main()
{
    int val1 = 10;
    int val2 = 30;
    swap(&val1, &val2);
    printf("val1: %d  val2: %d,",val1, val2);
}
