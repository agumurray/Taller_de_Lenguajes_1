#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Ingrese el orden de la matriz triangular inferior.");
    int n;
    scanf("%d", &n);

    int** mat = (int**) calloc(n, sizeof(int*));

    int c = 1;
    for (int i = 0; i <= n; i++) {
        mat[i] = (int*) calloc(c, sizeof(int));
        c++;
    }

    srand(time(NULL));

    c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = rand() % 21;
            printf("%d->", mat[i][j]);
        }
        c++;
        printf("\n");
    }

}