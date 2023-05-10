#include <stdio.h>
#include <stdlib.h>

void f (int * p);

int main() {
    int * ptr = NULL;
    f(ptr);

    if (ptr == NULL)
        printf("ptr es NULL\n");
    else
        printf("ptr no es NULL\n");
    return 0;
}

void f (int * p) {
    p = (int *) malloc(10*sizeof(int));
}

/*Se imprimer ptr es NULL
La asignación dentro de la función f() no afecta al puntero ptr en la función main() porque la función f() recibe una copia del valor del puntero ptr.

Cuando se llama a la función f() con ptr como argumento, se crea una copia del valor de ptr y se asigna a p dentro de la función. Después de eso, la función f() trabaja con la copia p y no con ptr en la función main(). Cualquier cambio hecho a p dentro de la función f() no afecta al puntero ptr en la función main().*/