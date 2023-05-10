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

void invertir(lista* l, lista* l_invertida) {
    lista aux = *l;
    while (aux != NULL) {
        agregarInicio(l_invertida, aux->dato);
        aux = aux->sig;
    }
}

int main() {
    lista l;
    inicializarLista(&l);
    int n = -1;
    while (n != 0) {
        printf("Ingrese un numero: ");
        scanf("%d", &n);
        if (n != 0) {
            agregarFinal(&l, n);
        }
    }
    lista l_invertida;
    inicializarLista(&l_invertida);
    invertir(&l, &l_invertida);
    printf("Lista original: ");
    imprimirLista(l);
    printf("\nLista invertida: ");
    imprimirLista(l_invertida);
    printf("Tamanio lista original: ");
    printf("%d", tamanio(&l));
    printf("\nTamanio lista invertida: ");
    printf("%d", tamanio(&l_invertida));
    vaciarLista(&l);
    vaciarLista(&l_invertida);
    return 0;
}