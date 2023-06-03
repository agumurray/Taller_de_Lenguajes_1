#include <stdio.h>
#include <stdlib.h>
#define SIZE 25


void imprimir(int * v, int size){
    int i;
    for (i=0; i<size; i++){
        printf("v[%d]= %d", i, v[i]);
    }
}
int main(){
    int v[SIZE];
    imprimir(v, SIZE); 
    return 0;
}

// El primer error esta en usar size como nombre de una variable siendo un numero explicitado en el define
// En precompilacion se reemplaza size por 25, por lo que el vector v tendra 25 elementos
//El error se soluciona cambiando el nombre de la variable o el define