#include <stdio.h>
#include <float.h>

struct rectangulo {
    float base;
    float altura;
};

void cargaRectangulo(struct rectangulo*);
float area(struct rectangulo);

int main() {
    struct rectangulo rect[10];
    float areaMin = FLT_MAX; 
    int rectMin;
    for (int i = 0; i<10; i++) {
        cargaRectangulo(&rect[i]);
        if (area(rect[i]) < areaMin) {
            rectMin = i;
            areaMin = area(rect[i]);
        }
    }

    printf("El numero de rectangulo con menor area es: %d. Con un area de: %f", rectMin, areaMin);

    return 0;
}

void cargaRectangulo(struct rectangulo* rect1) {
    printf("Ingrese la base del rectangulo: ");
    scanf("%f", &rect1->base);

    printf("Ingrese la altura del rectangulo: ");
    scanf("%f", &rect1->altura);
}

float area(struct rectangulo rect1) {
    return (rect1.base * rect1.altura);
}