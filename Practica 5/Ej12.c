#include <stdio.h>
#include <stdlib.h>

struct persona {
    int id;
    int dni;
    char apellido[50];
    char nombre[50];
    char trabajo[50];
    char correo[50];
    char ciudad[50];
    char pais[50];
};

struct nodo {
    struct persona dato;
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

void insertarOrdenado(lista*l, struct persona dato) {
    lista ant, nue, act;
    ant = *l;
    act = *l;
    nue = (lista) malloc(sizeof(nodo));
    nue->dato = dato;
    while((act!=NULL) && (act->dato.dni < dato.dni)) {
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
    FILE *f = fopen("textfiles/ej12/personas.csv", "r");
    if (f==NULL) {
        printf("Error al abrir archivo .csv.\n");
        return 1;
    }

    char linea[300];
    fgets(linea, 300, f);
    struct persona actual;
    lista l;
    inicializarLista(&l);
    while(!feof(f)) {
        fscanf(f, "%d;%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
                                  &actual.id, &actual.dni, actual.apellido,
                                  actual.nombre, actual.trabajo, actual.correo,
                                  actual.ciudad, actual.pais);
        insertarOrdenado(&l,actual);
    }
    lista aux = l;
    fclose(f);
    f = fopen("textfiles/ej12/personas.idx", "wb");
    while (aux!=NULL) {
        actual = aux->dato;
        fwrite(&(actual.dni), sizeof(int), 1, f);
        fwrite(&(actual.id), sizeof(int), 1, f);
        aux = aux->sig;
    }
    fclose(f);
    vaciarLista(&l);
    return 0;
}
