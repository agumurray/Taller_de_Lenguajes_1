#include <stdio.h>

int main() {
    char a, b;

    printf("Introduce el primer caracter: ");
    scanf("%c", &a);
    printf("El primer caracter es: %c\n", a);

    printf("Introduce el segundo caracter: ");
    scanf(" %c", &b);
    printf("El segundo caracter es: %c\n", b);

    return 0;
}
