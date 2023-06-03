#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define AREA_CIRCULO(r) ((PI)*(r)*(r))

int main() {
    float radio;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        radio = rand() % 10;
        printf("\nRadio: %.f", radio);
        printf("\nArea: %.2f", AREA_CIRCULO(radio));
    }
    return 0;
}