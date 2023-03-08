#include <stdio.h>

int main() {
    int a,b;
    char c;

    printf("Ingrese un numero entero: ");
    scanf("%d", &a);
    printf("Ingrese un numero entero: ");
    scanf("%d", &b);
    printf("Ingrese un operador aritmetico (+,-,*,/):");
    scanf(" %c", &c);

    switch (c) {
        case '+' : printf("%d",a+b);
        break;
        case '-' : printf("%d",a-b);
        break;
        case '*' : printf("%d",a*b);
        break;
        case '/' : printf("%d",a/b);
        break;

        default : printf("El caracter no corresponde a un operador aritmetico valido.");
    }

    return 0;

}