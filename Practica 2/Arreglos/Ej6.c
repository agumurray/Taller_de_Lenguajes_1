#include <stdio.h>

void contarDigitos(int[], int);
int main() {
    int n;
    printf("Ingrese un entero positivo: ");
    scanf("%d", &n);

    int cant[10] = {0};

    contarDigitos(cant, n);

    for(int i=0; i<10; i++) {
        printf("La cantidad de %d es: %d \n", i, cant[i]);
    }

    return 0;
}

void contarDigitos(int cant[], int n) {
    while (n!=0) {
        cant[n % 10]++;
        n/=10;
    }
}