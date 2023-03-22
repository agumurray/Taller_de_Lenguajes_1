#include <stdio.h>
#define longitud 6

float promedio(float[]);
float valorMinimo(float[]);
int posMax(float[]);

int main() {
    float flotantes[] = {1.5, 3.4, 0.75, 25.3, 6.3, 48.3};

    printf("El promedio de los valores del array es: %f \n", promedio(flotantes));
    printf("El valor minimo del array es: %f \n", valorMinimo(flotantes));
    printf("La posicion del valor maximo del array es: %d", posMax(flotantes));

    return 0;
}

float promedio(float flotantes[]) {
    float promedio = 0;
    for (int i=0; i<longitud; i++) {
        promedio += flotantes[i];
    }

    return (promedio/longitud);
}

float valorMinimo(float flotantes[]) { 
    float min = __FLT_MAX__;
    for (int i=0; i<longitud; i++) {
        if (flotantes[i] < min)
            min = flotantes[i];
    }
    return min;
}

int posMax(float flotantes[]) { 
    float maxValue= __FLT_MIN__;
    int maxIndex;
    for (int i = 0; i<longitud; i++) {
        if (flotantes[i] > maxValue) {
            maxValue = flotantes[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}