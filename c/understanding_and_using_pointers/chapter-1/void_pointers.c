#include<stdio.h>
#include<stdlib.h>

int main()
{
    // a void pointer is used to hold references for any data type
    void *pointer_value;
    int num = 3;
    int *pointer_int = &num;
    pointer_value = pointer_int;

    // void pointers needs to be casted if they'll be used.
    pointer_int = (int *) pointer_value;
    printf("%d ", *pointer_int); 
    

    size_t size = sizeof(void);
    size_t size2 = sizeof(void *);
    return 0;}
