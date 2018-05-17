#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <time.h>
#define tiempo 1

int main(int argc, char** argv) {
  struct timespec cgt1, cgt2;
  double ncgt;
  if (argc < 2) {
    perror("Falta tamanio del vector");
    exit(EXIT_FAILURE);
  }
  int N = atoi(argv[1]);
  int** matriz = malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) matriz[i] = malloc(N * sizeof(int));
  int* vector = malloc(N * sizeof(int));
  int* solucion = malloc(N * sizeof(int));

#pragma omp parallel
  {
#pragma omp for collapse(2)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) matriz[i][j] = i + j;
#pragma omp for
    for (int i = 0; i < N; i++) vector[i] = i;
#pragma omp for
    for (int i = 0; i < N; i++) solucion[i] = 0;
  }

  clock_gettime(CLOCK_REALTIME, &cgt1);
  int aux = 0;
  for (int i = 0; i < N; i++) {
    aux = 0;
#pragma omp parallel firstprivate(aux)
    {
#pragma omp for
      for (int j = 0; j < N; j++) aux += matriz[i][j] * vector[j];
#pragma omp atomic
      solucion[i] += aux;
    }
  }
  clock_gettime(CLOCK_REALTIME, &cgt2);
  ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
         (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

#if !tiempo
  printf("resultado: {");
  if (N < 12) {
    for (int i = 0; i < N; i++) printf("%d, ", solucion[i]);
    printf("\b\b}");
  } else {
    printf("%d, ..., %d}", solucion[0], solucion[N - 1]);
  }
#else
  printf("%f", ncgt);
#endif

  for (int i = 0; i < N; i++) free(matriz[i]);
  free(matriz);
  free(vector);
  free(solucion);
}