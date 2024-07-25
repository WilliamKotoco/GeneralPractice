#include <math.h>
#include <mpi.h>

#include <mpich-x86_64/mpi.h>
#include <stdio.h>
#include <string.h>

#define RECEIVER_RANK 0
int main(int argc, char *argv[]) {
  int curr_rank;
  int sender_rank;
  int num_process;
  const int tag = 0;
  char message[100];

  MPI_Status status;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &curr_rank);

  MPI_Comm_size(MPI_COMM_WORLD, &num_process);
  if (curr_rank != 0) {
    sprintf(message, "Greetings from process %d", curr_rank);

    /// sends message to other process with the RECEIVER_RANK id
    ///
    /// tags ir an int specified by the programmer that the system adds
    /// to the message envelope. It serves as bitfield
    ///
    /// example: if tag == 1, print the message, if tag == 2 stores in an array
    /// etc..
    ///
    ///
    /// the communicator is also important, two process with different
    /// communcators cannot talk to each other it is useful to distinct between
    /// communicators used by the main program and the ones used by a library
    /// function
    MPI_Send(message, strlen(message) + 1, MPI_CHAR, RECEIVER_RANK, tag,
             MPI_COMM_WORLD);

  } else {
    for (sender_rank = 1; sender_rank < num_process; sender_rank++) {

      /// if you want to receive message from any source, you can use:
      //       MPI_ANY_SOURCE
      MPI_Recv(message, 100, MPI_CHAR, sender_rank, tag, MPI_COMM_WORLD,
               &status);

      printf("%s \n", message);
    }
  }

  MPI_Finalize();
  return 0;
}
