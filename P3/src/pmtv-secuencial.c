#include <stdio.h>
#include <stdlib.h>

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

  // Inicializacion
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (j >= i)
        matriz[i][j] = i + j;
      else
        matriz[i][j] = 0;
  for (int i = 0; i < N; i++) vector[i] = i;

  // Calculo
  for (int i = 0; i < N; i++) {
    int aux = 0;
    for (int j = i; j < N; j++) aux += matriz[i][j] * vector[j];
    solucion[i] = aux;
  }

  // Salida
  printf("resultado: {");
  if (N < 12) {
    for (int i = 0; i < N; i++) printf("%d, ", solucion[i]);
    printf("\b\b}");
  } else {
    printf("%d,..., %d}", solucion[0], solucion[N - 1]);
  }

  // Liberacion memoria
  for (int i = 0; i < N; i++) free(matriz[i]);
  free(matriz);
  free(vector);
  free(solucion);
}