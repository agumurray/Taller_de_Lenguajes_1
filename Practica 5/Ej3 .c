#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    f = fopen("textfiles/precipitaciones.txt", "r");
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }

    int diaMax, cantMax, diaAct, cantAct;
    diaMax = cantMax = -1;
    int i = 1;

    while(!feof(f)) {
        fscanf(f, "%d-", &cantAct);
        diaAct = i;
        if (cantAct > cantMax) {
            cantMax = cantAct;
            diaMax = diaAct;
        }
        i++;
    }
    fclose(f);

    printf("El dia con mayor precipitaciones fue %d con %d milimetros.", diaMax, cantMax);
    return 0;
}