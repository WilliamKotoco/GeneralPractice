#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    int id; // process rank
    int number_process;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &number_process);

    printf("Hello world from process <%d> \n ", id);
    
    fflush(stdout);
    MPI_Finalize();
    return 0;
}
