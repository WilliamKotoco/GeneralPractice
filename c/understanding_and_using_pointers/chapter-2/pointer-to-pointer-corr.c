#include<stdio.h>
#include <stdlib.h>
void print_array(int *);
void change_array(int **arr)
{
    *arr = malloc (10 * sizeof(int));
    for (int i = 0; i < 10; i++)
        *(arr[i]) = 3*i; // double pointer acess
}

int main()
{
    int array[10];
    for (int i = 0 ;i < 10; i++)
        array[i] = 4*i;
    print_array(array);
    printf("\n");
    *array = NULL;
    change_array(array);

}

void print_array(int *arr)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}
