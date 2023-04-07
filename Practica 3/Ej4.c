#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct carta {
    int numero;
    char palo[10];
};

void cargarMazo(struct carta[]);
void imprimirMazo(struct carta[]);
void barajar(struct carta[]);
struct carta sacarCarta(struct carta[]);

int main() {
    struct carta mazo[48];
    cargarMazo(mazo);
    imprimirMazo(mazo);
    printf("FIN");
    barajar(mazo);
    imprimirMazo(mazo);
    printf("FIN");

    struct carta carta1 = sacarCarta(mazo);
    printf("Palo %s Nro %d", carta1.palo, carta1.numero);
}

void cargarMazo(struct carta mazo[]) {
    char palos[4][10] = {{"Basto"}, {"Espada"}, {"Oro"}, {"Copa"}};

    for (int i = 0; i<4; i++) {
        for(int j=1; j<=12; j++) {
            strcpy(mazo[(i*12) + j - 1].palo, palos[i]);
            mazo[(i*12) + j - 1].numero = j;
    }
        }
    }

void imprimirMazo(struct carta mazo[]) {
    for (int i = 0; i<48; i++) {
        printf("Palo: %s \n", mazo[i].palo);
        printf("Numero: %d \n", mazo[i].numero);
    }
}

void barajar(struct carta mazo[]) {
    srand(time(NULL));
    struct carta actual;
    for (int i=0; i<48; i++) {
        actual = mazo[i];
        int n = rand() % 48 + 1;
        mazo[i] = mazo[n];
        mazo[n] = actual;
    }
}

struct carta sacarCarta(struct carta mazo[]) {
    struct carta tope = mazo[0];

    for(int i=0; i<48; i++) {
        mazo[i - 1] = mazo[i];
    }

    mazo[47] = tope;

    return tope;
}