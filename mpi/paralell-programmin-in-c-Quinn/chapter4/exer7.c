#include<mpi.h>
#include<stdio.h>
#define MAIN_PROCESSOR 0
// calculate the sum 1+2+3...+number.
int main(int argc, char *argv[])
{
    int number;
    scanf ("%d", &number);


    int number_process;
    int id;
    
    int partial_sum = 0;
    int total;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &number_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);


    /*
        Broadcasts the value read in scanf to every other processor. MPI uses distributed
        memory, so it doesn't share memory.
    */
           MPI_Bcast(&number, 1, MPI_INT, MAIN_PROCESSOR, MPI_COMM_WORLD);


    
    for (int i = id; i <= number; i += number_process) 
        partial_sum += i;

    MPI_Reduce (&partial_sum, &total, 1,MPI_INT, MPI_SUM, MAIN_PROCESSOR, MPI_COMM_WORLD); 
    MPI_Finalize();
    if (id == MAIN_PROCESSOR)
        printf("%d \n", total);

    return 0;
}
