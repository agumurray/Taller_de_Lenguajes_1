#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int[], int);
void inicializar(int [], int);
void imprimir(int [],int);

int main() {
    srand(time(NULL));

    int vector[30];
    inicializar(vector, sizeof(vector)/sizeof(vector[0]));
    sort(vector, sizeof(vector)/sizeof(vector[0]));
    imprimir(vector, sizeof(vector)/sizeof(vector[0]));

    return 0;
}

void inicializar(int vector[], int len) {
    for(int i=0; i<len; i++) {
        vector[i] = rand() % 200 + 1;
    }
}

void sort(int array[], int len){
    int i, key, j;
    for (i = 1; i < len; i++) {                     
        key = array[i];                             
        j = i-1;                                    
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void imprimir(int vector[], int len) {
    for (int i = 0; i<len; i++) {
        printf("%d \n", vector[i]);
    }
}