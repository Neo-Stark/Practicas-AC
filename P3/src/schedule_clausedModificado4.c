#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
int main(int argc, char **argv) {
  int i, n = 200, chunk, a[n], suma = 0;
  int nchunk = 0;
  omp_sched_t kind = 0;
  static char *sched_kind[] = {"static", "dynamic", "guided", "auto"};
  if (argc < 3) {
    fprintf(stderr, "\nFalta iteraciones o chunk \n");
    exit(-1);
  }
  n = atoi(argv[1]);
  if (n > 200) n = 200;
  chunk = atoi(argv[2]);
  for (i = 0; i < n; i++) a[i] = i;
#pragma omp parallel
  {
#pragma omp for schedule(dynamic, chunk) firstprivate(suma) lastprivate(suma)
    for (i = 0; i < n; i++) {
      suma = suma + a[i];
      printf(" thread %d suma a[%d]=%d suma=%d \n", omp_get_thread_num(), i,
             a[i], suma);
    }
#pragma omp single
    {
      omp_get_schedule(&kind, &nchunk);
      printf(
          "\nDentro de la region parallel\n "
          "dyn-var:%d\n nthreads-var:%d\n "
          "thread-limit-var:%d\n "
          "run-sched-var:\n\tKind:%s  chunk:%d\n "
          "num_threads:%d\n num_procs:%d\n in_parallel:%d\n ",
          omp_get_dynamic(), omp_get_max_threads(), omp_get_thread_limit(),
          sched_kind[kind - 1], nchunk, omp_get_num_threads(),
          omp_get_num_procs(), omp_in_parallel());
    }
  }

  omp_get_schedule(&kind, &nchunk);
  printf(
      "\nDentro de la region parallel\n "
      "dyn-var:%d\n nthreads-var:%d\n "
      "thread-limit-var:%d\n "
      "run-sched-var:\n\tKind:%s  chunk:%d\n "
      "num_threads:%d\n num_procs:%d\n in_parallel:%d\n ",
      omp_get_dynamic(), omp_get_max_threads(), omp_get_thread_limit(),
      sched_kind[kind - 1], nchunk, omp_get_num_threads(), omp_get_num_procs(),
      omp_in_parallel());

  printf("Fuera de 'parallel for' suma=%d\n", suma);
}