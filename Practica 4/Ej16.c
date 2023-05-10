#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Ingrese un numero entero para concocer sus divisores: \n");
    int n;
    scanf("%d", &n);
    int* divisores = NULL;
    printf("Estos son los divisores de %d: ", n);
    int i = n;
    int c = 0;
    while (i!=0) {
        if ((n%i) == 0) {
            ++c;
            divisores = (int*) realloc(divisores, c*sizeof(int));
            divisores[c-1] = i;
        }
        i--;
    }
    for (int i = 0; i<c; i++) 
        printf("%d, ", divisores[i]);
    free(divisores);
}