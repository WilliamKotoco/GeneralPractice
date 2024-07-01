#include <__clang_cuda_builtin_vars.h>
#include <cstdlib>
#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

// Error checking macro
#define CUDA_CHECK_RETURN(value)                                                                                       \
    {                                                                                                                  \
        cudaError_t _m_cudaStat = value;                                                                               \
        if (_m_cudaStat != cudaSuccess)                                                                                \
        {                                                                                                              \
            fprintf(stderr, "Error %s at line %d in file %s\n", cudaGetErrorString(_m_cudaStat), __LINE__, __FILE__);  \
            exit(1);                                                                                                   \
        }                                                                                                              \
    }

/// each thread produces one output matrix element
__device__ void add_matrix_kernal_1(float **A, float **B, float **C)
{
    int row = threadIdx.x + blockDim.x * blockIdx.x;

}

/// each thread produces one output matrix row
__device__ void add_matrix_kernal_3(float **A, float **B, float **C)
{
    int row = threadIdx.x + blockDim.x * blockIdx.x;
    
    int size = blockDim.x > N ? N : blockDim.x;

    for (int i = 0 ; i < size; i++)
    {
      C[row][i] = A[row][i] + B[row][i];
    }
}

/// each thread produces one output matrix column
__device__ void add_matrix_kernal_2(float **A, float **B, float **C)
{
    return;
}

/// not necessary the __host__ once it is by default
__host__ float **matrix_alloc()
{
    float **matrix = (float **)malloc(N * sizeof(float *));

    for (int i = 0; i < N; i++)
    {
        matrix[i] = (float *)malloc(N * sizeof(float));
    }

    return matrix;
}

float **matrix_cuda_malloc()
{
    float **matrix;
    CUDA_CHECK_RETURN(cudaMalloc((void **)&matrix, N * sizeof(float *)));

    for (int i = 0; i < N; i++)
    {
        CUDA_CHECK_RETURN(cudaMalloc((void **)&matrix[i], N * sizeof(float)));
    }

    return matrix;
}

void matrix_add(float **h_A, float **h_B, float **h_C)
{
    float **d_A = matrix_cuda_malloc();
    float **d_B = matrix_cuda_malloc();
    float **d_C = matrix_cuda_malloc();

    cudaMemcpy(d_A, h_A, N * sizeof(float *), cudaMemcpyKind::cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, N * sizeof(float *), cudaMemcpyKind::cudaMemcpyHostToDevice);



    cudaMemcpy(h_C, d_C, N * sizeof(float *), cudaMemcpyKind::cudaMemcpyDeviceToHost);
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}
int main()
{
    float **h_A = matrix_alloc();
    float **h_B = matrix_alloc();
    float **h_C = matrix_alloc();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            h_A[i][j] = (float)rand() / 1000;
            h_B[i][j] = (float)rand() / 1000;
        }
    }

    matrix_add(h_A, h_B, h_C);
    return 0;
}
