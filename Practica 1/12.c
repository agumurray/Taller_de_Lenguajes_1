#include <stdio.h>
#include <math.h>

int main() {
    int i;
    float f;

    for (i=1; i<=10; i++) {
        f = i;
        printf("Raiz cuadrada de %d = %f\n",i,sqrt(f));
        printf("El cuadrado de %d = %f\n", i, pow(f,2));
        printf("El cubo de %d = %f\n", i,pow(f,3));
    }

    return 0;
}