#include <stdio.h>
#include <stdlib.h>

float* reservarMemoria(int n) {
    return (float*) malloc(n * sizeof(float));
}

void inicializarArreglo(float* arreglo, int n) {
    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arreglo[i]);
    }
}

float calcularPromedio(float* arreglo, int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arreglo[i];
    }
    return suma / n;
}

void liberarMemoria(float* arreglo) {
    free(arreglo);
}

int main() {
    int n;
    printf("Ingrese el tamanio del arreglo: ");
    scanf("%d", &n);

    float* arreglo = reservarMemoria(n);

    inicializarArreglo(arreglo, n);

    float promedio = calcularPromedio(arreglo, n);
    printf("El promedio de los valores es: %f\n", promedio);

    liberarMemoria(arreglo);

    return 0;
}