#include <stdio.h>

void sumarMatrices(int[][3], int[][3], int[][3]);
void imprimirMatriz(int[][3]);

int main() {
    int matrizA[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrizB[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrizC[3][3] = {0};

    imprimirMatriz(matrizA);
    imprimirMatriz(matrizB);

    sumarMatrices(matrizA,matrizB,matrizC);
    imprimirMatriz(matrizC);

    return 0;
}

void imprimirMatriz(int matriz[][3]) {
    for(int i = 0; i<3;i++) {
        for (int j=0; j<3;j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
} 

void sumarMatrices(int matrizA[][3], int matrizB[][3], int matrizC[][3]) {
    for(int i = 0; i<3;i++) {
        for (int j=0; j<3;j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}