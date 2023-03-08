#include <stdio.h>

int damePar();

int main() {
    int a,b;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &a);

    for (int i=1; i<=a; i++)
        printf("%d \n", damePar());

    return 0;
}

int damePar() {       
    static int a = -2;
    return (a += 2);
}