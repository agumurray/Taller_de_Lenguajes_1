#include <stdio.h>

void procesarArray(float[], float *,float *,int *);

int main() {
    float flotantes[10] = {1.2, 2.4, 0.9, 0.4, 43.6, 52.7, 99.21, 3.44, 6.32, 7.7};
    float promedio,min;
    int maxIndex;

    procesarArray(flotantes, &promedio, &min, &maxIndex);

    printf("Promedio del array: %f \n", promedio);
    printf("Valor minimo del array: %f \n", min);
    printf("Posicion del valor maximo del array: %d", maxIndex);
    
    return 0;
}

void procesarArray(float flotantes[], float *promedio, float *min, int *maxIndex) {
    *promedio = 0;
    *min = __FLT_MAX__;
    int max = __FLT_MIN__;

    for(int i=0; i<10; i++) {
        *promedio += flotantes[i];
        if (flotantes[i] < *min)
            *min = flotantes[i];
        
        if (flotantes[i] > max) {
            max = flotantes[i];
            *maxIndex = i;
        }
    }

    *promedio /= 10;
}