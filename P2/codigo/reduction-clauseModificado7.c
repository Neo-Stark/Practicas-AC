#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_set_num_threads() 1
#endif
int main(int argc, char **argv) {
  int i, n = 20, a[n], suma = 0;
  if (argc < 2) {
    fprintf(stderr, "Falta iteraciones\n");
    exit(-1);
  }
  n = atoi(argv[1]);
  if (n > 20) {
    n = 20;
    printf("n=%d", n);
  }
  for (i = 0; i < n; i++) a[i] = i;
  omp_set_num_threads(4);
  int aux = 0;
#pragma omp parallel firstprivate(aux)
  {
    if (omp_get_thread_num() == 0)
      for (i = 0; i < n / 4; i++) aux += a[i];
    else if (omp_get_thread_num() == 1)
      for (i = n / 4; i < n / 2; i++) aux += a[i];
    else if (omp_get_thread_num() == 2)
      for (i = n / 2; i < 3 * n / 4; i++) aux += a[i];
    else if (omp_get_thread_num() == 3)
      for (i = 3 * n / 4; i < n; i++) aux += a[i];

#pragma omp atomic
    suma += aux;
  }
  printf("Tras 'parallel' suma=%d\n", suma);
}