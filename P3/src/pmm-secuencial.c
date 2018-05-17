#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc < 2) {
    perror("Falta tamanio del vector");
    exit(EXIT_FAILURE);
  }
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
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      matriz1[i][j] = 2;
      matriz2[i][j] = 2;
      solucion[i][j] = 0;
    }

  // Calculo
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++)
        solucion[i][j] += matriz1[i][k] * matriz2[k][j];
    }
  }

  // Salida
  printf("resultado: {");
  if (N < 12) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) printf("%d, ", solucion[i][j]);
    printf("\b\b}");
  } else {
    printf("%d,..., %d}", solucion[0][0], solucion[N - 1][N - 1]);
  }

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