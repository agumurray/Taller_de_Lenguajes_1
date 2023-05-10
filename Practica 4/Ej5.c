#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void procesarOracion(char* sd,int* ptrMayus, int*ptrMinus ) {
    for (int i = 0; i < strlen(sd); i++) {
        if ((sd[i]>='a') && (sd[i]<='z'))
            (*ptrMinus)++;
        else if ((sd[i]>='A') && (sd[i]<='Z'))
            (*ptrMayus)++;
    }   
}

int main() {
    char *sd;
    sd = (char*) malloc(100*sizeof(char));
    int cantMayus, cantMinus;
    for (int i = 0; i < 10; i++) {
        cantMayus = 0;
        cantMinus = 0;
        printf("Ingrese la oracion numero: %d\n", i+1);
        gets(sd);
        procesarOracion(sd, &cantMayus, &cantMinus);
        printf("La cantidad de mayusculas es: %d\n", cantMayus);
        printf("La cantidad de minuscualas es: %d\n", cantMinus);
    }
    free(sd);
    return 0;
}