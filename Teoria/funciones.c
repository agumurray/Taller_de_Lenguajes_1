#include <stdio.h>

int mayor(int a, int b, int c);
int main() {
    int a,b,c;
    printf("Ingrese un nro entero: ");
    scanf("%d", &a);
    printf("Ingrese un nro entero: ");
    scanf("%d", &b);
    printf("Ingrese un nro entero: ");
    scanf("%d", &c);

    printf("El numero mayor es: %d ", mayor(a,b,c));
}

int mayor(int a,int b,int c) {
    if ((a>b) && (a>c))
        return a;
    else if((b>a) && (b>c))
        return b;
   return c; 
}