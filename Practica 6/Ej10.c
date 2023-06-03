#include <stdio.h>
#include "lib/imath.h"

int main() {
    int numero;
    while (1) {
        printf("Ingrese un numero (0 para salir): ");
        scanf("%d", &numero);
        if (numero == 0) {
            break;
        }
        if (par(numero)) {
            printf("Cuadrado: %d\n", cuadrado(numero));
            printf("Cubo: %d\n", cubo(numero));
        } else {
            printf("Factorial: %d\n", factorial(numero));
        }
    }
    return 0;
}