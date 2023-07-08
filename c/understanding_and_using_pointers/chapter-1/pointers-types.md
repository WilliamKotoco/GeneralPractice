## size_t
used for declaring variables for sizes such as the number of characteres and array indexes
Do not use for pointers. It can be used to store size of pointers

size_t size = sizeof(int *);

## intptr_t and uintptr_t
they're used for storing pointer addresses, giving a portable and efficient way of declaring pointers. The uintptr_t is the unsigned version

int num;

intptr_t *pnum = '&num';

