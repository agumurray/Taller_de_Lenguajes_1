#include <stdio.h>

void swapArray(int [], int);

int main() {
    int vector[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i;

    for(i=0; i<15; i++) {
        printf("vector[%d] = %d \n", i, vector[i]);
    }
    printf("\n \n \n");


    swapArray(vector, sizeof(vector)/sizeof(vector[0]));

    for(i=0; i<15; i++) {
        printf("vector[%d] = %d \n", i, vector[i]);
    }

    return 0;
}

void swapArray(int vector[], int longitud) {
    int *fin = vector + longitud - 1;
    int inicioActual,finActual;
    for (int i=0; i<=longitud/2 ; i++) {
        inicioActual = *vector;
        finActual = *fin;
        *vector = finActual;
        *fin = inicioActual;
        vector++;
        fin--;
    }
}