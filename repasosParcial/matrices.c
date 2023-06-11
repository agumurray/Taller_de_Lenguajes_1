#include <stdio.h>
#include <stdlib.h>
#define FIL 3
#define COL 4

//    |0|1|2|3 |0|1|2|3|0|1 |2 |3 | 
// v= |0|0|21|0|0|0|0|0|0|22|0 |0 |

//    |0|1|2|3|0|1 |2|3|0|1|2|3 |
// m= |0|0|0|0|0|21|0|0|0|0|0|22|

int sumaUltimaFila(int *, int, int);
int nashe (int[][COL], int , int);

int main() {
    int v[FIL][COL] = {0}, *ptr;
    int *m = (int*) calloc(FIL*COL, sizeof(int));

    printf("%d  %d\n", sizeof(v), sizeof(m));

    v[1][1] = 10;

    ptr = &v[1][0];
    *(ptr-2) = 21;
    *(m+5) = 21;
    *(ptr+5) = 22;
    *(m+12*COL/4-1) = 22;

    printf("La suma de los numeros. ");
    printf("de la ultima fila de m es = \n");
    printf("%d\n", sumaUltimaFila(m, FIL, COL));

    printf("La suma de los nros de la ultima fila es: %d\n", sumaUltimaFila(v, FIL, COL));

    free(m);

    return 0;
}

int sumaUltimaFila(int* m, int cantFilas, int cantColumnas) {
    int suma = 0;
    for (int i = 0; i < cantColumnas; i++) {
        suma += m[(cantFilas-1)*cantColumnas + i];
    }
    return suma;
}

int nashe(int m [][COL], int cantFilas, int cantColumnas) {
    int suma = 0;
    for (int i = 0; i < cantColumnas; i++) {
        suma += m[cantFilas-1][i];
    }
    return suma;
}