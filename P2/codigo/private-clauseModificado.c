#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
int main() {
  int i, n = 7;
  int a[n], suma = 0;
  for (i = 0; i < n; i++) a[i] = i;
  printf("valor suma fuera de parallel: %d\n", suma);
    printf("valor suma dentro de parallel: %d\n", suma);
#pragma omp parallel private(suma)
  {
#pragma omp for
    for (i = 0; i < n; i++) {
      suma = suma + a[i];
      printf("thread %d suma a[%d] / ", omp_get_thread_num(), i);
    }
    printf("\n* thread %d suma= %d", omp_get_thread_num(), suma);
  }
  printf("\n");
}