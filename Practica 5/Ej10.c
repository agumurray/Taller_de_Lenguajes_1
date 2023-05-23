#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jugador {
    char nombre[20], apellido[20];
    int edad, titulos,ranking;
    float fortuna;
};

int actualizarRanking(char nombre[20], char apellido[20], FILE *f);

int main() {
    char nombre[20];
    char apellido[20];
    FILE *f;
    f = fopen("textfiles/jugadores.dat", "rb+");
    printf("Ingrese el nombre del jugador: ");
    scanf("%s", nombre);
    printf("\n");
    printf("Ingrese el apellido del jugador: ");
    scanf("%s", apellido);
    while (strcmp(nombre, "ZZZ") != 0) {
        if (!actualizarRanking(nombre, apellido,f)) {
            printf("Jugador no encontrado.\n");
        }
        printf("Ingrese el nombre del jugador: ");
        scanf("%s", nombre);
        printf("\n");
        printf("Ingrese el apellido del jugador: ");
        scanf("%s", apellido);
    }
    struct jugador j;
    while (fread(&j, sizeof(struct jugador), 1, f) != 0) {
        printf("%s, %s, %d, %d, %d, %f\n", j.nombre, j.apellido, j.edad, j.titulos, j.ranking, j.fortuna);
    }
    fclose(f);
    return 0;
}

int actualizarRanking(char nombre[20], char apellido[20], FILE *f) {
    struct jugador j;
    int ranking;
    while (fread(&j, sizeof(struct jugador),1,f) != 0) {
        if (strcmp(j.nombre, nombre) == 0 && strcmp(j.apellido, apellido) == 0) {
            printf("Ingrese el nuevo ranking: ");
            scanf("%d", &ranking);
            j.ranking = ranking;
            fseek(f, -sizeof(struct jugador), SEEK_CUR);
            fwrite(&j, sizeof(struct jugador), 1, f);
            fseek(f, 0, SEEK_SET);
            return 1;
        }
    }
    fseek(f, 0, SEEK_SET);
    return 0;
}
