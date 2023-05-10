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

void insertarOrdenado(lista*l, int dato) {
    lista ant, nue, act;
    ant = *l;
    act = *l;
    nue = (lista) malloc(sizeof(nodo));
    nue->dato = dato;
    while((act!=NULL) && (act->dato < dato)) {
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
    lista l;
    lista impares;
    lista pares;
    inicializarLista(&l);
    inicializarLista(&impares);
    inicializarLista(&pares);
    int n = -1;
    while (n!=0) {
        printf("Ingrese un numero entero positivo: \n");
        scanf("%d", &n);
        if (n!=0) {
            insertarOrdenado(&l, n);
            if (n%2==0) {
                agregarInicio(&pares, n);
            }
            else {
                agregarInicio(&impares, n);
            }
        }
    }
    printf("Lista original: ");
    imprimirLista(l);
    printf("\nLista pares: ");
    imprimirLista(pares);
    printf("\nLista impares: ");
    imprimirLista(impares);
    vaciarLista(&l);
    vaciarLista(&pares);
    vaciarLista(&impares);
    return 0;
}
