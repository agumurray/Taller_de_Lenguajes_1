#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarMatriz(int** m,int n) {
    int c = 0;
    srand(time(NULL));
    int aux;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            aux = rand() % 21;
            m[i][j] = aux;
        }
        c++;
    }
}

void imprimirMatriz(int** m, int n) {
    int c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d, ", m[i][j]);
        }
        printf("\n");
        c++;
    }
}

void liberarMemoria(int** m, int n) {
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    printf("Ingrese de que orden quiere la matriz triangular inferior: ");
    int n;
    scanf("%d", &n);
    int c = 1;
    //reserva memoria matriz dinamica con acceso de doble indice
    int** m;
    m = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i<n; i++) {
        m[i] = (int*) malloc(c*sizeof(int));
        c++;
    }

    inicializarMatriz(m, n);
    imprimirMatriz(m,n);
    liberarMemoria(m, n);
    return 0;
}