#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LETRAS 26

struct palabra {
    char palabra[16];
    float dificultad;
};

float getDiff(char *palabra, float *frecuencias);

int main() {
    float frecuencias[LETRAS] = {12.53,1.42,4.68,5.86,13.68,0.69,1.01,0.70,6.25,0.44,0.01,4.97,3.15,6.71,8.68,2.51,0.88,6.87,7.98,4.63,3.93,0.90,0.02,0.22,0.90,0.52};

    FILE *origen = fopen("palabras.txt", "r");
    FILE *destino = fopen("dificultad.dat", "wb");

    char buffer[16];
    float dificultad;
    struct palabra aux;

    while (fgets(buffer, 16, origen) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; 
        dificultad = getDiff(buffer, frecuencias);
        if (dificultad) {
            strcpy(aux.palabra,buffer);
            aux.dificultad = dificultad;
            fwrite(&aux, sizeof(struct palabra), 1, destino);
        }
    }
    fclose(origen);
    fclose(destino);

    return 0;
}

float getDiff(char *palabra, float *frecuencias) {
    float dificultad;
    int len = strlen(palabra);
    if (len<4||len>14)
        return 0;
    for (int i = 0; i<len; i++) {
        dificultad += frecuencias[palabra[i] - 'a'] * frecuencias[palabra[i] - 'a'];
    }
    return dificultad;
}