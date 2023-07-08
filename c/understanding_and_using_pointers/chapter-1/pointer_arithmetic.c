#include<stdlib.h>
#include<stdio.h>

int main()
{
    int vector[] = {10,20,40,90};
    int *pvector = vector;

    // when we use the index to acess the values of array, the compiler
    // translates it to *(pvector + index)
    for (int i =0 ; i < 4; i++)
        printf("%d ", *(pvector+i));
    printf("\n");
     
    pvector += 3;
    
    for (int i = 0; i < 4; i++)
            printf("%d ", *(pvector - i));

    int *p1 = vector;
    int *p2 = vector + 3;
    
    // by this subtraction we can find the distance between two values of an array
    // also we could find their distance in addres by multiplying for it's sizeof
    printf("\n %d ", p2 - p1);
}
