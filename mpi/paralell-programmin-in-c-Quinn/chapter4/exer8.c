#include<mpi.h>
#include<stdio.h>
#include<stdbool.h>
#define MAX 10000
#define MAIN_PROCESSOR 0
/**
 * See how many two consecutive odd integers are both prime in a range
 * [0, 10.000]
 * 
 * For example, we have 3,5 and 11 all prime numbers, however the odd after 7 (9) is not prime
 * 
 * So, in a range of [0, 10] the answer is 2 (3,5, 7) even though we have 4 primes. 
*/

bool isPrime(int number);

int main(int argc, char *argv[])
{

    int partial_solutions;
    int total_solutions;

    int number_of_process;
    int id;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &number_of_process);

    int magic_number = (number_of_process % 2 ) == 0 ? 1 : 0;

//TODO: como fazer com que cada processor passe somente pelos ímpares ?
    for (int i = id; i < MAX; i += number_of_process + magic_number)
    {
        if(isPrime(i) && isPrime(i+2))
            partial_solutions++;
    }


    MPI_Reduce(&partial_solutions, &total_solutions, 1, MPI_INT, MPI_SUM, MAIN_PROCESSOR, MPI_COMM_WORLD);

    MPI_Finalize();

    if (id == MAIN_PROCESSOR)
        printf("Number of consecutives odds that are primes in the given range: %d", total_solutions);
    return 0;
}

bool isPrime(int number)
{
    for (int i = 2 ;i < number/2; i++)
    {
        if (number % i == 0)
            return false;
    }
}
