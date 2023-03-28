#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
int size = 0;
int main()
{

   int *arr = create_new_int_arraylist(arr, 23);
   size++;
   for (int i = 0; i < 10; i++)
   {
      size++;
      arr = append_int_arraylist(arr, 2 * i + 1);
   }

   for (int i = 0; i < size - 1; i++)
     // printf("\n %d ", arr[i]);
   arr = clear_int_arraylist(arr);

   for (int i = 0; i < 10; i++)
   {
      size++;
      arr = append_int_arraylist(arr, 2 * i + 1);
   }
   for (int i = 0; i < size ; i++)
      printf(" %d ", arr[i]);

   if(contains_int_arraylist(arr, 3))
      puts("existe!");
   printf("%d", contains_int_arraylist(arr, 3));

   arr = remove_int_arraylist(arr, 3);

   printf("\n");
    for (int i = 0; i < size - 1; i++)
       printf(" %d ", arr[i]);

   return 0;
}