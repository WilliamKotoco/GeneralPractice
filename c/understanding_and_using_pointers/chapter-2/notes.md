# Chapter 2

## Free
It's necessary to assign `*p = null` after the liberation of the pointer's memory. The free operator does not necessarly give it back the OS, the memory space can be kept in the RAM avaliable for use. Thus, if you don't assign null to a pointer, many problems may happen like unpredictable behaviour and segmentation fault due the variable pointing to something that doesn't exist or received another value.

## Function pointers

Pointer which points to a function. Example `int (*sum) (double)` points to a function that receives double and returns integer.

Ex2: `void (*f) (char *)`

Ex3: `double * (*f3) (int, int)` points to a function that receives two integers and return a pointer to a double
