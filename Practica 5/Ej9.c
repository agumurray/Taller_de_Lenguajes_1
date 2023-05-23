#include <stdio.h>
#include <stdlib.h>

struct jugador {
    char nombre[20], apellido[20];
    int edad, titulos,ranking;
    float fortuna;
};

int main() {
    FILE *f = fopen("textfiles/jugadores.dat", "wb");
    if (f == NULL) {
        printf("El archivo tuvo un problema al abrirse.");
        return 1;
    }

    struct jugador j;

    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre del jugador: ");
        scanf("%s", j.nombre);
        printf("\n");
        printf("Ingrese el apellido del jugador: ");
        scanf("%s", j.apellido);
        printf("\n");
        printf("Ingrese la edad del jugador: ");
        scanf("%d", &(j.edad));  
        printf("\n");
        printf("Ingrese los titulos del jugador: ");
        scanf("%d", &(j.titulos));
        printf("\n");
        printf("Ingrese el ranking del jugador: ");
        scanf("%d", &(j.ranking));
        printf("\n");
        printf("Ingrese la fortuna del jugador: ");
        scanf("%f", &(j.fortuna));
        printf("\n");

        fwrite(&j, sizeof(struct jugador), 1, f);
    }
    
    struct jugador maxRanking;
    struct jugador maxTitulos;

    maxRanking.ranking = 999999;
    maxTitulos.titulos = -1;

    fclose(f);
    f = fopen("textfiles/jugadores.dat", "rb");

    for (int i = 0; i < 3; i++) {
        fread(&j, sizeof(struct jugador), 1, f);
        if (j.ranking < maxRanking.ranking) {
            maxRanking = j;
        }
        if (j.titulos > maxTitulos.titulos) {
            maxTitulos = j;
        }
    }
    fclose(f);

    printf("El jugador con mejor ranking es: %s, %s\n", maxRanking.nombre, maxRanking.apellido);
    printf("El jugador con mas titulos es: %s, %s", maxTitulos.nombre, maxTitulos.apellido);

    return 0;
}