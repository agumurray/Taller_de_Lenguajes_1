#include <stdio.h>

void matrizTranspuesta(int matriz[][3], int filas, int columnas) {
  int i, j;
  printf("Matriz transpuesta:\n");
  for (j = 0; j < columnas; j++) {
    for (i = 0; i < filas; i++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int f, c;
  printf("Ingrese el número de filas de la matriz: ");
  scanf("%d", &f);
  printf("Ingrese el número de columnas de la matriz: ");
  scanf("%d", &c);
  int matriz[f][c];
  int i, j;
  for (i = 0; i < f; i++) {
    for (j = 0; j < c; j++) {
      printf("Ingrese el elemento (%d,%d): ", i+1, j+1);
      scanf("%d", &matriz[i][j]);
    }
  }
  printf("Matriz original:\n");
  for (i = 0; i < f; i++) {
    for (j = 0; j < c; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  matrizTranspuesta(matriz, f, c);
  return 0;
}