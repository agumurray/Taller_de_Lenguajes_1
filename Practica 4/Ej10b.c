#include <stdio.h>
#include <stdlib.h>


void inicializarVector(double* vector, int n) {
    double aux;
    for (int i = 0; i < n; i++ ) {
        printf("Ingrese el valor para la posicion %d", i+1);
        scanf("%lf", &aux);
        *(vector+i) = aux;
        printf("Usted ingreso: %lf\n", *(vector+i));
    }
}

double promedio(double* vector, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma+=*(vector+i);
    }
    return(suma/n);
}

int main() {
    int n;
    printf("Ingrese de que tamanio quiere el arreglo: ");
    scanf("%d", &n);
    double* vector = (double*) malloc(n*sizeof(double));
    inicializarVector(vector, n);
    promedio(vector, n);
    printf("El promedio es %lf", promedio(vector, n));
    free(vector);
    return 0;
}