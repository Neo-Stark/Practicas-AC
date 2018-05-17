#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#else
#endif
int main(int argc, char** argv) {
  if (argc < 2) {
    perror("Falta tamanio del vector");
    exit(EXIT_FAILURE);
  }
  struct timespec cgt1, cgt2;
  double ncgt;
  int N = atoi(argv[1]);
  int** matriz1 = malloc(N * sizeof(int*));
  int** matriz2 = malloc(N * sizeof(int*));
  int** solucion = malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    matriz1[i] = malloc(N * sizeof(int));
    matriz2[i] = malloc(N * sizeof(int));
    solucion[i] = malloc(N * sizeof(int));
  }

  // Inicializacion
#pragma omp parallel for
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      matriz1[i][j] = 2;
      matriz2[i][j] = 2;
      solucion[i][j] = 0;
    }

  // Calculo
  printf("%d\n", omp_get_max_threads());
  clock_gettime(CLOCK_REALTIME, &cgt1);
#pragma omp parallel for schedule(static)
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++)
        solucion[i][j] += matriz1[i][k] * matriz2[k][j];
    }
  }
  clock_gettime(CLOCK_REALTIME, &cgt2);
  ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
         (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));
  // Salida
  printf("resultado: {");
  if (N < 12) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) printf("%d, ", solucion[i][j]);
    printf("\b\b}");
  } else {
    printf("%d,..., %d}\n", solucion[0][0], solucion[N - 1][N - 1]);
  }
  printf("%f\n", ncgt);

  // Liberacion memoria
  for (int i = 0; i < N; i++) {
    free(matriz1[i]);
    free(matriz2[i]);
    free(solucion[i]);
  }
  free(matriz1);
  free(matriz2);
  free(solucion);
}