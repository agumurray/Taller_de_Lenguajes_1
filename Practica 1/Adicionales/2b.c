#include <stdio.h>

int toBinary(int a, int b, int c);

int main() {
    int a;
    printf("Ingrese un numero para transformarlo a binario: ");
    scanf("%d", &a);

    printf("%d = %d", a, toBinary(a,0,1));
}

int toBinary(int a, int b, int c) {
    if (!(a > 0))
        return b;
    else {
        b += a%2 * c;
        a/=2;
        c*=10;

        return(toBinary(a,b,c));
    }
}