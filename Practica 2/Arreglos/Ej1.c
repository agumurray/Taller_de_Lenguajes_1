#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[50];
    for (int i=0; i<50; i++) {
        numeros[i] = rand();
    }

    int impares = 0;
    int pares =  0;

    for (int i=0; i<50; i+=2) {
       if (numeros[i] % 2 != 0) 
        impares++;
    }

    for (int i=1; i<50; i+=2) {
       if (numeros[i] % 2 == 0) 
        pares++;
    }

    printf("La cantidad de numeros impares en posiciones pares es: %d \n", impares);
    printf("La cantidad de numeros pares en posiciones impares es: %d", pares);
    
    return 0;
}