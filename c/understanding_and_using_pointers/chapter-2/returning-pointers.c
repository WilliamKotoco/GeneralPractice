#include<stdio.h>
#include <stdlib.h>

int *allocate_array()
{
    int *arr = malloc(30 * sizeof(int));
    for(int i = 0; i < 30; i++)
        arr[i] = 3*i;
    return arr;
}

int main()
{
    int *array = allocate_array();

    for (int i = 0; i < 30; i++)
        printf("%d ", array[i]);
}
