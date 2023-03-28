#include "functions.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
extern int size;
int *create_new_int_arraylist(int *arr, int elem)
{
    arr = malloc(sizeof(int));
    arr[0] = elem;
}
int *append_int_arraylist(int *arr, int elem)
{
    arr = realloc(arr, size * sizeof(int));
    arr[size-1]= elem;
    return arr;
}
int *clear_int_arraylist( int *arr)
{
    free(arr);
    arr = malloc(sizeof(int));
    size =1;
    return arr;
}
int contains_int_arraylist(int *arr, int elem)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if(arr[i] == elem)
            return 1;
    }
    return 0;
}

int getIndexOfElement_int_arraylist(int *arr, int elem)
{
    if(contains_int_arraylist(arr, elem))
    {
        int i;
        for (i=0; i <size; i++)
        {
            if(arr[i] == elem)
                return i;
        }
    }
    return -1;
}
int *remove_int_arraylist(int *arr, int elem)
{
    int index = getIndexOfElement_int_arraylist(arr, elem), aux;
    int *temp = malloc(  (size - 1) * sizeof(int));
    if(index != 0 )
        memcpy(temp, arr, index * sizeof(int)); // copia tudo antes do index
    if (index != size -1)
        memcpy(temp + index, arr + index +1, (size - index - 1) *sizeof(int)); // copia tudo deopis do index
    free(arr);
    return temp;
} 