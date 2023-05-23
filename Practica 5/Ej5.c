#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG 300

char** leerArchivo(const char* nombreArchivo, int* numPalabras);

void liberarMemoria(char** palabras, int numPalabras);

int estaEnDiccionario(char** palabras,char index[], int numPalabras);

int main() {
    const char* nombreArchivo = "textfiles/diccionario.txt";
    int numPalabras;
    char** palabras = leerArchivo(nombreArchivo, &numPalabras);


    if (palabras != NULL) {
    char end[] = "ZZZ";
    char index[LONG];
    printf("Ingrese una palabra para saber si se encuentra en el diccionario: ");
    scanf("%s", index);
    while(strcmp(index, end) != 0) {
        if (estaEnDiccionario(palabras,index, numPalabras) == 1)
            printf("La palabra esta en el diccionario.\n");
        else
            printf("La palabra no esta en el diccionario.\n");
        printf("Ingrese una palabra para saber si se encuentra en el diccionario: ");
        scanf("%s", index);
    }

    liberarMemoria(palabras, numPalabras);
    return 0;
    }
}

int estaEnDiccionario(char** palabras,char index[], int numPalabras) {
    int res;
    for(int i = 0; i<numPalabras; i++) {
        res = strcmp(index, *(palabras+i));
        if (res == 0)
            return 1;
    }
    return 0;
}

char** leerArchivo(const char* nombreArchivo, int* numPalabras) {
    FILE *f = fopen(nombreArchivo, "r");
    if (f == NULL) {
        printf("No se puedo abrir el archivo.");
        return NULL;
    }

    *numPalabras = 0;
    char buffer[LONG];
    while(fgets(buffer, LONG, f)!=NULL) {
        (*numPalabras)++;
    }

    fseek(f, 0, SEEK_SET);

    char** palabras = (char**) malloc(*numPalabras * sizeof(char*));
    if (palabras == NULL) {
        printf("No se puedo asignar memoria.");
        fclose(f);
        return NULL;
    }

    int i = 0;
    while (fgets(buffer, LONG, f) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; //Eliminar el salto de linea si existe, reemplazarlo por \0 (fin string)
        palabras[i] = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
        if (palabras[i] == NULL) {
            printf("No se puedo asignar memoria.");
            fclose(f);
            liberarMemoria(palabras, i);
            return NULL;
        }
        strcpy(palabras[i], buffer);
        i++;
    }

    fclose(f);
    return palabras;
}

void liberarMemoria(char** palabras, int numPalabras) {
    for (int i = 0; i < numPalabras; i++) {
        free(palabras[i]);
    }
    free(palabras);
}