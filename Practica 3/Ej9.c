#include <stdio.h>

typedef enum {DOMINGO, LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO} dias;

void imprimeDias();
int main() {
    imprimeDias();
    return 0;
}

void imprimeDias() {
    char vectorDias[7][11] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    int i; 
    for (i = DOMINGO; i<SABADO; i++) {
        printf("%s ", vectorDias[i]);
   }
}
