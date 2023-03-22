#include <stdio.h>

void retornarEscalar(int[3][3], int c);
void imprimirMatriz(int[3][3]);

int main() {
    int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    imprimirMatriz(matriz);

    printf("Ingrese el escalar por el que desea multiplicar la matriz: ");
    int c;
    scanf("%d", &c);

    retornarEscalar(matriz,c);
    imprimirMatriz(matriz);

    return 0;
}

void imprimirMatriz(int matriz[3][3]) {
    int i,j;
    for(i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void retornarEscalar(int matriz[3][3], int c) {
    int i,j;
    for(i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            matriz[i][j] *= c;
        }
    }    
}