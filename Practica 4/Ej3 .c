#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int n;
    printf("Ingrese de cuantas posiciones quiere que sea el array simple: ");
    scanf("%d", &n);
    int *pd;
    pd = (int*) malloc(n*sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        pd[i] = rand();
    int max = -1;
    for (int i = 0; i < n; i++)
        printf("Posicion %d: %d.\n", i+1, pd[i]);
    for (int i = 0; i < n; i++) {
        if (pd[i]>max)
            max = pd[i];
    }
    printf("El valor maximo en el array es: %d", max);
    free(pd);
    return 0;
}