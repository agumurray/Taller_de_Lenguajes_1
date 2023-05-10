#include <stdio.h>
#include <stdlib.h>

int** crearPiramide(int** p, int f) {
    int c = 1;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if ((j==0) || (j == c-1))
                p[i][j]=1;
            else {
                p[i][j] = p[i-1][j-1] + p[i-1][j];
            }
        }
        c++;
    }
    return p;
}

void imprimirPiramide(int** m, int n) {
    int c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d, ", m[i][j]);
        }
        printf("\n");
        c++;
    }
}

void destruirPiramide(int** m, int n) {
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int n;
    printf("Ingrese de cuantas filas quiere la piramide: ");
    scanf("%d", &n);
    int c = 1;
    //reserva memoria matriz dinamica con acceso de doble indice
    int** piramide;
    piramide = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i<n; i++) {
        piramide[i] = (int*) malloc(c*sizeof(int));
        c++;
    }
    
    piramide = crearPiramide(piramide, n);
    imprimirPiramide(piramide, n);
    destruirPiramide(piramide, n);
    return 0;
}