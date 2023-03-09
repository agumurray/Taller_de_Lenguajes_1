#include <stdio.h>

int toBinary(int a);
int main() {
    int a;
    printf("Ingrese un numero para transformarlo a binario: ");
    scanf("%d", &a);

    printf("%d = %d", a, toBinary(a));
}

int toBinary(int a) {
    int binario = 0;
    for (int i=1 ; a>0; i*=10) {
        binario += a%2 * i;
        a /= 2;
    }

    return binario;
}