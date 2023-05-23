#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    f = fopen("textfiles/apuestas.txt", "r");
    float montoTotal = 0;
    float montoActual;
    int nroApuesta;
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }

    while(!feof(f)) {
        fscanf(f, "%d|%f;", &nroApuesta, &montoActual);
        montoTotal += montoActual;
    }
    fclose(f);

    printf("El monto total apostado es $%.2f", montoTotal);
    return 0;
}