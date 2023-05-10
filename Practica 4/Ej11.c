#include <stdio.h>
#include <stdlib.h>

void inicializarMatriz(int** mat, int f, int c) {
    int aux;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("Ingrese el valor para la fila %d y columna %d\n: ",i+1,j+1 );
            scanf("%d", &aux);
            mat[i][j] = aux;
        }
    }
}

void printMultiplosTres(int** mat, int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if ((mat[i][j]%3)==0)
                printf("%d - es multiplo de tres\n",mat[i][j]);
        }
    }
}

void vaciarMatriz(int** mat , int f , int c) {
    for (int i = 0; i < f; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main() {
    printf("Ingrese cuantas filas quiere: \n");
    int f;
    scanf("%d", &f);
    printf("Ingrese cuantas columnas quiere: \n");
    int c;
    scanf("%d", &c);

    //reserva memoria matriz dinamica con acceso de doble indice
    int** mat;
    mat = (int**) calloc(f,sizeof(int*));
    for (int i = 0; i<f; i++) {
        mat[i] = (int*) calloc(c,sizeof(int));
    }

    inicializarMatriz(mat, f, c);
    printMultiplosTres(mat, f, c);
    vaciarMatriz(mat, f, c);
    return 0;
}