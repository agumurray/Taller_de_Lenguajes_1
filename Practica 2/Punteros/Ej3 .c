#include <stdio.h>

int main() {
    int x[5]={1,2,3,4,5};
    int * p = x;
    printf("La direccion memoria de p es %p \n", &p); //direccion de memoria de la variable de tipo puntero 'p'
    printf("La direccion la que apunta p es %p \n", p); //direccion de memoria del valor de la primer posicion del vector x
    printf("El valor al que apunta p es %d \n", *p); //valor de la primer posicion del vector x
    p++;
    printf("La direccion memoria de p ahora es %p \n", &p); //direccion de memoria de la variable de tipo puntero 'p' (misma que antes)
    printf("La direccion la que apunta p ahora es %p \n", p); //direccion de memoria del valor de la segunda posicion del vector x
    printf("El valor al que apunta p ahora es %d \n", *p); //valor de la segunda posicion del vector x
    return 0;
}