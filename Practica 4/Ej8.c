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
    imprimirLista(l);
    printf("Tamanio: %d", tamanio(&l));
    printf("Los numeros en la lista creada que no sean multiplos del numero a ingresar, seran eliminados: ");
    scanf("%d", &n);
    lista act = l;
    lista ant = l;
    lista prox;
    while (act != NULL) {
        if ((act->dato%n)!=0) {
            prox = act->sig;
            if (act == l) {
                l = act->sig;
            }
            else {
                ant->sig = act -> sig;
            }
            free(act);
            act = prox;
        }
        else {
            ant = act;
            act = act -> sig;
        }
    }
    imprimirLista(l);  
    printf("Tamanio: %d", tamanio(&l));
    vaciarLista(&l);
    return 0;
}