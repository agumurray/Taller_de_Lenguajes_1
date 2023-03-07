//el operador sizeof() nos permite conocer el tamanio en bytes de cualquier tipo de dato.

#include <stdio.h>
int main() {
    int a = sizeof(int);
    int b = sizeof(char);
    int c = sizeof(float);
    int d = sizeof(double);

    printf("%d %d %d %d", a,b,c,d);
}