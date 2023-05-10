#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int** m, int f, int c) {
    int aux;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("Ingrese un valor para la fila %d y columna %d\n", i+1, j+1);
            scanf("%d", &aux);
            m[i][j] = aux;
            printf("Usted ingreso el valor %d\n", m[i][j]);
        }
    }
}

void vaciarMatriz(int** m , int f , int c) {
    for (int i = 0; i < f; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int f = 2;
    int c = 3;

    int** m = (int**) calloc(f,sizeof(int*));
    for (int i = 0; i<f; i++) {
        m[i] = (int*) calloc(c,sizeof(int));
    }
    cargarMatriz(m, f, c);
    vaciarMatriz(m, f, c);
    return 0;
}