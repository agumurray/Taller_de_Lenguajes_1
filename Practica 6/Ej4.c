#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SQUAREOF(x) ((x)*(x))

int main() {
    int xin=3;
    printf("\nxin=%i",xin);
    printf("\nSQUAREOF(xin)=%i", SQUAREOF(xin));
    printf("\nSQUAREOF(xin+4)=%i", SQUAREOF(xin+4));
    printf("\nSQUAREOF(xin+xin)=%i", SQUAREOF(xin+xin));

    return 0;
}

/*El programa muestra el uso de una macro llamada SQUAREOF(x) para calcular el cuadrado de un número utilizando la definición x*x
Los resultados no son los esperados si no se le colocan parentesis a los argumentos dentro de la macro*/