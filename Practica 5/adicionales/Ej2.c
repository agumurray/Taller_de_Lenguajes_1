#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct palabra {
    char palabra[16];
    float dificultad;
};

struct nodo {
    struct palabra dato;
    struct nodo *sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

void inicializarLista(lista* l) {
    *l = NULL;
}

void vaciarLista(lista* l) {
    lista aux;

    while(*l != NULL) {
        aux = *l;
        *l = (*l)->sig;
        free(aux);
    }
}

void insertarOrdenado(lista*l, struct palabra dato) {
    lista ant, nue, act;
    ant = *l;
    act = *l;
    nue = (lista) malloc(sizeof(nodo));
    nue->dato = dato;
    while((act!=NULL) && (act->dato.dificultad < dato.dificultad)) {
        ant = act;
        act = act->sig;
    }

    nue->sig = act;
    if (ant == act) {
        *l = nue;
    }
    else {
        ant->sig = nue; 
    }
}

int main() {
    FILE *f = fopen("dificultad.dat", "rb");
    struct palabra aux;
    lista l;
    inicializarLista(&l);
    int cantPalabras = 0;
    while (fread(&aux, sizeof(struct palabra), 1, f) == 1) {
        insertarOrdenado(&l, aux);
        cantPalabras++;
    }
    lista actual = l;
    int restoPalabras = cantPalabras % 10;
    int cantRedonda = cantPalabras - restoPalabras;
    FILE *file;
    for (int i = 1; i <= 10; i++) {
        char filename[10];
        sprintf(filename, "ahorcado/palabras10/dif%d.txt", i);
        
        file = fopen(filename, "a");
        
        if (file == NULL) {
            printf("No se pudo abrir el archivo %s\n", filename);
            return 1;
        }
        
        // Escribir en el archivo
        for (int i = 0; i < cantRedonda / 10; i++) {
            fprintf(file, "%s\n", actual->dato.palabra);
            actual = actual->sig;
        }
        
        // Cerrar el archivo
        fclose(file);
        
        printf("Archivo %s creado y modificado correctamente\n", filename);
    }
    f = fopen("ahorcado/palabras10/dif10.txt", "a");
    for (int i = 0; i<restoPalabras; i++) {
        fprintf(f, "%s\n", actual->dato.palabra);
        actual = actual->sig;
    }
    fclose (file);
    fclose(f);

    // Vaciar la lista
    vaciarLista(&l);

    return 0;
}