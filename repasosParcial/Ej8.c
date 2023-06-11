#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;


void inicializarLista(lista* l) {
    *l = NULL;
}

void agregarFinal(lista* l, int dato) {
    lista act, aux=(*l);
    act = (lista) malloc(sizeof(nodo));
    act->dato = dato;
    act->sig = NULL;

    if((*l) == NULL) 
        (*l) = act;
    else {
        while(aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = act;
    }
}

void eliminarNodo(lista *l, int dato) {
    if (*l == NULL) {
        printf("La lista esta vacia");
        return;
    }

    lista nodoActual = *l;
    lista nodoAnterior = NULL;

    while(nodoActual != NULL && nodoActual->dato!=dato) {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }

    if (nodoActual == NULL) {
        printf("No se encontro el nodo.");
        return;
    }

    if (nodoAnterior ==NULL) {
        *l = nodoActual->sig;
    } else {
        nodoAnterior->sig = nodoActual->sig;
    }

    free(nodoActual);
}

void imprimirLista(lista l) {
    lista aux = l;
    while(aux != NULL) {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
}

void liberarLista(lista*l) {
    lista nodoActual = *l;
    lista nodoSiguiente = NULL;

    while (nodoActual != NULL) {
        nodoSiguiente = nodoActual->sig;
        eliminarNodo(l, nodoActual->dato);
        nodoActual = nodoSiguiente;
    }
}


int main() {
    lista l;
    inicializarLista(&l);
    agregarFinal(&l, 1);
    agregarFinal(&l, 2);
    agregarFinal(&l, 3);
    agregarFinal(&l, 4);
    agregarFinal(&l, 5);

    imprimirLista(l);

    liberarLista(&l);

    imprimirLista(l);
}