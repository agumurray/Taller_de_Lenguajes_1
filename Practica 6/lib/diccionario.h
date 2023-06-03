//Implemento diccionario utilizando una lista enlazada (no tiene orden alfabetico)
//Si quisera que tenga orden alfabetico, el agregarPalabra deberia ser ordenado
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef dicccionario_h
#define dicccionario_h

typedef struct Palabra{
    char palabra[50];
    struct Palabra* siguiente;
} Palabra;

typedef struct Diccionario {
    Palabra* primera;
} Diccionario;

Diccionario* crearDiccionario() {
    Diccionario* diccionario = (Diccionario*) malloc(sizeof(Diccionario));
    diccionario -> primera = NULL;
    return diccionario;
}

int existePalabra(Diccionario* diccionario, const char* palabra) {
    Palabra* palabraActual = diccionario -> primera;
    while (palabraActual != NULL) {
        if (strcmp(palabraActual -> palabra, palabra) == 0) {
            return 1;
        }
        palabraActual = palabraActual -> siguiente;
    }
    return 0;
}

int agregarPalabra(Diccionario* diccionario, const char* palabra) {
    //Verificar si la palabra ya existe en el diccionario
    if (existePalabra(diccionario, palabra)) {
        return 0;
    }

    //Crear nodo para la palabra
    Palabra* nuevaPalabra = (Palabra*) malloc(sizeof(Palabra));
    strcpy(nuevaPalabra -> palabra, palabra);
    nuevaPalabra -> siguiente = NULL;

    //Agregar la palabra
    if (diccionario -> primera == NULL) {
        diccionario -> primera = nuevaPalabra;
    }
    else {
        Palabra *ultimaPalabra = diccionario -> primera;
        while (ultimaPalabra -> siguiente != NULL) {
            ultimaPalabra = ultimaPalabra -> siguiente;
        }
        ultimaPalabra -> siguiente = nuevaPalabra;
    }
    return 1; 
}



int eliminarPalabra(Diccionario* diccionario, const char* palabra) {
    if (!existePalabra(diccionario, palabra)) {
        return 0;
    }

    Palabra *palabraActual = diccionario->primera;
    Palabra* palabraAnterior = NULL;
    while (palabraActual != NULL) {
        if (strcmp(palabraActual->palabra, palabra) == 0) {
            if (palabraAnterior == NULL) {
                diccionario->primera = palabraActual->siguiente;
            }
            else {
                palabraAnterior -> siguiente  = palabraActual -> siguiente;
            }
            free(palabraActual);
            return 1;
        }
        palabraAnterior = palabraActual;
        palabraActual = palabraActual -> siguiente;
    }
    return 0;
}

void cargarDesdeArchivo(Diccionario* diccionario, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return;
    }

    char palabra[50];
    while (fgets(palabra, sizeof(palabra), archivo) != NULL) {
        //Remover el salto de linea
        palabra[strlen(palabra) - 1] = '\0';
        if (!existePalabra(diccionario, palabra)) {
            agregarPalabra(diccionario, palabra);
        } 
    }
    fclose(archivo);
}

void cargarEnArchivo(Diccionario* diccionario, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return;
    }

    Palabra* palabraActual = diccionario -> primera;
    while (palabraActual != NULL) {
        fprintf(archivo, "%s\n", palabraActual -> palabra);
        palabraActual = palabraActual -> siguiente;
    }

    fclose(archivo);
}

void destruirDiccionario(Diccionario* diccionario) {
    Palabra* palabraActual = diccionario -> primera;
    while (palabraActual != NULL) {
        Palabra* palabraSiguiente = palabraActual -> siguiente;
        free(palabraActual);
        palabraActual = palabraSiguiente;
    }
    free(diccionario);
}


#endif 