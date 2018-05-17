#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#else
typedef int omp_sched_t;
inline void omp_get_schedule(omp_sched_t* kind, int* chunk) {
  *kind = 0;
  *chunk = 0;
}
#endif
#define tiempo 1

int main(int argc, char** argv) {
  if (argc < 2) {
    perror("Falta tamanio del vector");
    exit(EXIT_FAILURE);
  }

  int N = atoi(argv[1]);
  int** matriz = malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) matriz[i] = malloc(N * sizeof(int));
  int* vector = malloc(N * sizeof(int));
  int* solucion = malloc(N * sizeof(int));
  omp_sched_t kind = 0;
  int chunk = 0;
  static char* sched_kind[] = {"static", "dynamic", "guided", "auto"};
  struct timespec cgt1, cgt2;
  double ncgt;

  // Inicializacion
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (j >= i)
        matriz[i][j] = i + j;
      else
        matriz[i][j] = 0;
  for (int i = 0; i < N; i++) vector[i] = i;

  // Calculo
  clock_gettime(CLOCK_REALTIME, &cgt1);
#pragma omp parallel for schedule(runtime)
  for (int i = 0; i < N; i++) {
    int aux = 0;
    // printf("Thread: %d\t IT: %d\n", omp_get_thread_num(), i);
    for (int j = i; j < N; j++) aux += matriz[i][j] * vector[j];
    solucion[i] = aux;
  }
  clock_gettime(CLOCK_REALTIME, &cgt2);
  ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
         (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

  // Salida
  omp_get_schedule(&kind, &chunk);
  printf("Kind:%s  chunk:%d\n", sched_kind[kind - 1], chunk);
  printf("resultado: {");
  if (N < 12) {
    for (int i = 0; i < N; i++) printf("%d, ", solucion[i]);
    printf("\b\b}\n");
  } else {
    printf("%d,..., %d}\n", solucion[0], solucion[N - 1]);
  }
  printf("%f\n", ncgt);
  // Liberacion memoria
  for (int i = 0; i < N; i++) free(matriz[i]);
  free(matriz);
  free(vector);
  free(solucion);
}