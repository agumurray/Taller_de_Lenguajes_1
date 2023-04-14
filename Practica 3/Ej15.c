#include <stdio.h>

struct figura {
    int tipo;
    union {
    struct {
        double radio;
    } circulo;

    struct {
        double radioMayor;
        double radioMenor;
    } elipse;

    struct {
        double lado;
    } cuadrado;

    struct {
        double base;
        double altura;
    } rectangulo;

    struct {
        double base;
        double altura;
    } triangulo;
    };
};
 

double calcularSuperficie(struct figura f);
int main() {
    struct figura f;
    printf("Ingrese el tipo de figura: ");
    scanf("%d", &f.tipo);
    switch (f.tipo) {
        case 0:
            printf("Ingrese el radio: ");
            scanf("%lf", &f.circulo.radio);
            break;
        case 1:
            printf("Ingrese el radio mayor: ");
            scanf("%lf", &f.elipse.radioMayor);
            printf("Ingrese el radio menor: ");
            scanf("%lf", &f.elipse.radioMenor);
            break;
        case 2:
            printf("Ingrese el lado: ");
            scanf("%lf", &f.cuadrado.lado);
            break;
        case 3:
            printf("Ingrese la base: ");
            scanf("%lf", &f.rectangulo.base);
            printf("Ingrese la altura: ");
            scanf("%lf", &f.rectangulo.altura);
            break;
        case 4:
            printf("Ingrese la base: ");
            scanf("%lf", &f.triangulo.base);
            printf("Ingrese la altura: ");
            scanf("%lf", &f.triangulo.altura);
            break;
    }
    printf("La superficie es: %.2lf", calcularSuperficie(f));
    return 0;
}
double calcularSuperficie(struct figura f) {
    switch (f.tipo) {
        case 0:
            return 3.1416 * f.circulo.radio * f.circulo.radio;
        case 1:
            return 3.1416 * f.elipse.radioMayor * f.elipse.radioMenor;
        case 2:
            return f.cuadrado.lado * f.cuadrado.lado;
        case 3:
            return f.rectangulo.base * f.rectangulo.altura;
        case 4:
            return f.triangulo.base * f.triangulo.altura / 2;
        default: 
            return 0;
    }
}
