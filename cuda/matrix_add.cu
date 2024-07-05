#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

#define CUDA_CHECK_RETURN(value)                                               \
  {                                                                            \
    cudaError_t _m_cudaStat = value;                                           \
    if (_m_cudaStat != cudaSuccess) {                                          \
      fprintf(stderr, "Error %s at line %d in file %s\n",                      \
              cudaGetErrorString(_m_cudaStat), __LINE__, __FILE__);            \
      exit(1);                                                                 \
    }                                                                          \
  }

__global__ void add_matrix_kernal(float *d_a, float *d_b, float *d_c) {
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int column = blockIdx.x * blockDim.x + threadIdx.x;

  if (row < N && column < N)
    d_c[row * N + column] = d_a[row * N + column] + d_b[row * N + column];
}

void add_matrix(float *h_a, float *h_b, float *h_c) {
  float *d_a;
  float *d_b;
  float *d_c;

  CUDA_CHECK_RETURN(cudaMalloc(&d_a, N * N * sizeof(float)));
  CUDA_CHECK_RETURN(cudaMalloc(&d_b, N * N * sizeof(float)));
  CUDA_CHECK_RETURN(cudaMalloc(&d_c, N * N * sizeof(float)));

  cudaMemcpy(d_a, h_a, N * N * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, N * N * sizeof(float), cudaMemcpyHostToDevice);

  dim3 threads_per_block(16, 16);
  dim3 blocks_per_grid((N + threads_per_block.x - 1) / threads_per_block.x,
                       (N + threads_per_block.y - 1) / threads_per_block.y);

  add_matrix_kernal<<<blocks_per_grid, threads_per_block>>>(d_a, d_b, d_c);

  cudaMemcpy(h_c, d_c, N * N * sizeof(float), cudaMemcpyDeviceToHost);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
}
int main() {
  float *h_a = (float *)malloc((N * N) * sizeof(float));
  float *h_b = (float *)malloc((N * N) * sizeof(float));
  float *h_c = (float *)malloc((N * N) * sizeof(float));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      h_a[i * N + j] = (float)rand() / (RAND_MAX / 100.0);
      h_b[i * N + j] = (float)rand() / (RAND_MAX / 100.0);
    }
  }

  add_matrix(h_a, h_b, h_c);

  printf("%f + %f = %f", h_a[0], h_b[0], h_c[0]);

  return 0;
}
