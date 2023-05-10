#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int* m, int f, int c) {
    int aux;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("Ingrese un valor para la fila %d y columna %d\n", i+1, j+1);
            scanf("%d", &aux);
            *(m+c*i+j) = aux;
            printf("Usted ingreso el valor %d\n", *(m+c*i+j));
        }
    }
}

int main() {
    int f = 2;
    int c = 3;

    int* m = (int*) malloc(f*c*sizeof(int));
    cargarMatriz(m, f, c);
    free(m);
    return 0;
}