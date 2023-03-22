#include <stdio.h>

int main() {
    int n;
    printf("Ingrese un entero positivo: ");
    scanf("%d", &n);

    int cant[10] = {0};

    contarDigitos(cant, n);
}