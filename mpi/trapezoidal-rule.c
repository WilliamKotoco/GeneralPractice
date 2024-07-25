// #include <mpich-x86_64/mpi.h>
#include <mpi.h>
#include <stdio.h>

#define DEST_RANK 0

/// calculates local integral
float trap(float local_a, float local_b, int local_n, float h);

float f(float x);

void get_data(float *a, float *b, int *num_trapezoids, int curr_rank,
              int num_proc);

int main(int argc, char **argv) {
  /// mpi info
  int curr_rank;
  int num_proc;
  MPI_Status status;
  float a, b;
  int num_trapezoids;
  float total_integral;

  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
  MPI_Comm_rank(MPI_COMM_WORLD, &curr_rank);

  get_data(&a, &b, &num_trapezoids, curr_rank, num_proc);

  float h = (b - a) / num_trapezoids;

  int local_num_trapezoids = num_trapezoids / num_proc;

  float local_a = a + curr_rank * local_num_trapezoids * h;
  float local_b = local_a + local_num_trapezoids * h;

  float integral = trap(local_a, local_b, local_num_trapezoids, h);

  if (curr_rank == 0) {
    total_integral = integral;

    for (int source = 1; source < num_proc; source++) {
      MPI_Recv(&integral, 1, MPI_FLOAT, source, 0, MPI_COMM_WORLD, &status);

      total_integral += integral;
    }

  }

  else {
    MPI_Send(&integral, 1, MPI_FLOAT, DEST_RANK, 0, MPI_COMM_WORLD);
  }

  if (curr_rank == 0) {
    printf("integral from %f to %f = %f \n", a, b, total_integral);
  }

  MPI_Finalize();
}

float trap(float local_a, float local_b, int local_n, float h) {

  float integral = (f(local_a) + f(local_b)) / 2.0;

  float x = local_a;

  for (int i = 1; i <= local_n - 1; i++) {
    x = x + h;
    integral = integral + f(x);
  }

  integral *= h;

  return integral;
}

float f(float x) { return 2 * x + 3; }

void get_data(float *a, float *b, int *num_trapezoids, int curr_rank,
              int num_proc) {

  const int source = 0;
  MPI_Status status;

  if (curr_rank == 0) {
    printf("Enter A, B, and num of trapezoids \n");
    scanf("%f %f %d", a, b, num_trapezoids);

    /// sends for every process
    for (int dest = 1; dest < num_proc; dest++) {

      /// changing tags for indicating the type of data:
      /// 0 -> a
      /// 1 -> b
      /// 2 -> trapezoids

      MPI_Send(a, 1, MPI_FLOAT, dest, 0, MPI_COMM_WORLD);
      MPI_Send(b, 1, MPI_FLOAT, dest, 1, MPI_COMM_WORLD);
      MPI_Send(num_trapezoids, 1, MPI_INT, dest, 2, MPI_COMM_WORLD);
    }
  } else {
    MPI_Recv(a, 1, MPI_FLOAT, source, 0, MPI_COMM_WORLD, &status);
    MPI_Recv(b, 1, MPI_FLOAT, source, 1, MPI_COMM_WORLD, &status);
    MPI_Recv(num_trapezoids, 1, MPI_FLOAT, source, 2, MPI_COMM_WORLD, &status);
  }
}
