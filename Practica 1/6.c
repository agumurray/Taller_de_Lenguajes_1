#include <stdio.h>

int main() {
    float km;
    
    printf("Ingrese una distancia en kilometros \n");
    scanf("%f", &km);

    printf("%f = %f", km, km/1.609);

    return 0;
}