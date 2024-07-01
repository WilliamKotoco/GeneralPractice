#include <cstdlib>
#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000
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

/// there is no need for loops, each thread corresponds to an interation
__global__ void vec_add_kernel(float *A, float *B, float *C)
{

    /// size of block * the id identifies unically the index of the original
    /// vector
    int index = threadIdx.x + (blockDim.x * blockIdx.x);

    /// the if statemant is necessary since the size of the vector may not match
    /// the block size, once the block size is multiple of 32. It is necessary to
    /// discard the remaining threads
    if (index < N)
        C[index] = A[index] + B[index];
}
void vec_add(float *h_a, float *h_b, float *h_c)
{

    /// declaring the device arrays
    float *d_a;
    float *d_b;
    float *d_c;

    /// allocating memory in device
    CUDA_CHECK_RETURN(cudaMalloc((void **)&d_a, N * sizeof(float)));
    CUDA_CHECK_RETURN(cudaMalloc((void **)&d_b, N * sizeof(float)));
    CUDA_CHECK_RETURN(cudaMalloc((void **)&d_c, N * sizeof(float)));

    /// copying from host to device
    cudaMemcpy(d_a, h_a, N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, N * sizeof(float), cudaMemcpyHostToDevice);

    /// number of blocks and number of threads within a block
    vec_add_kernel<<< ceil(N/ 256.0), 256>>>(d_a, d_b, d_c);

    /// copying from device to host after performing the vector addition i
    cudaMemcpy(h_c, d_c, N * sizeof(float), cudaMemcpyDeviceToHost);


    printf("teste %f \n", h_c[0]);
    /// free device's memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
}
int main()
{
    float *h_a = (float *)malloc(N * sizeof(float));
    float *h_b = (float *)malloc(N * sizeof(float));
    float *h_c = (float *)malloc(N * sizeof(float));

    for (int i = 0; i < N; i++)
    {
        h_a[i] = (float)rand() / (RAND_MAX/100.0);
        h_b[i] = (float)rand() / (RAND_MAX / 100.0);
    }

    vec_add(h_a, h_b, h_c);

    printf("Test: %f + %f = %f", h_a[0], h_b[0], h_c[0]);

    return 0;
}
