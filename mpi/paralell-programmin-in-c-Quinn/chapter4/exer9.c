/*
 * Program to determine for all integers less than 10000 the largest gap between two prime numbers.
 *
 * for example: 3 and 5 has 1 gap (4)
 *
 * 7 and 11 has 4 gaps
 * */

#define MAX 10000

#include<stdio.h>
#include<mpi.h>
#include<stdbool.h>

bool isPrime(int x);

int main(int argc, char *argv[])
{
    int processors;
    int id;

    int biggest_processor_gap;
    int biggest_gap;
    int count;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &processors);

    biggest_processor_gap = 0;
    count = 0;
    
    // divides in contiguos subsets, defining the bounds of each processors
    const int fraction = MAX/processors;
    const int start  = id *  fraction;
    const int end = (id + 1 ) *  fraction;
    

    for (int i = start; i < end; i++)
    {
        if(isPrime(i))
        {
            if (count > biggest_processor_gap)
                biggest_processor_gap = count;

            count = 0;
        }

        else
            count++;
    }

    MPI_Reduce(&biggest_processor_gap, &biggest_gap, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Finalize();
 
    if (id == 0)
        printf("%d ", biggest_gap);
    return 0;
}

bool isPrime(int x)
{

    for (int i = 2; i < x/2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
