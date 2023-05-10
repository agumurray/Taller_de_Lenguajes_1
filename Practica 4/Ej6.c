#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
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

void agregarInicio(lista* l, int dato) {
    lista act;
    act = (lista) malloc(sizeof(nodo));
    act->dato=dato;
    act->sig=(*l);
    (*l)=act;
}

void agregarFinal(lista* l, int dato) {
    lista act, aux=(*l);
    act = (lista) malloc(sizeof(nodo));
    act->dato = dato;
    act->sig = NULL;

    if((*l)==NULL) {
        (*l) = act;
    }
    else {
        while(aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig=act;
    }
}

int tamanio(lista* l){
    lista aux=(*l);
    int cont=0;
    while(aux!=NULL){
        aux=aux->sig;
        cont++;
    }

    return cont;
}

void imprimirLista(lista l){
    lista aux=l;
        while(aux!=NULL){
            printf("%d, ",aux->dato);
            aux=aux->sig;
    }

}

int main() {
    lista l;
    inicializarLista(&l);
    agregarFinal(&l, 1);
    agregarFinal(&l, 2);
    agregarFinal(&l, 3);
    agregarInicio(&l, 4);
    agregarInicio(&l, 5);
    imprimirLista(l);
    printf("\n");
    printf("Tamanio: %d\n", tamanio(&l));
    vaciarLista(&l);
    imprimirLista(l);
    printf("\n");
    printf("Tamanio: %d\n", tamanio(&l));
    return 0;
}