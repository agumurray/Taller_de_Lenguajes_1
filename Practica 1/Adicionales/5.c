#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int a,b,n,first;
    n = 1;

    printf("Ronda %d.\n", n);
    a = rand() % 6 + 1;
    b = rand() % 6 + 1;
    printf("Dado 1: %d\n", a);
    printf("Dado 2: %d\n", b);

    if((a+b==7) || (a+b==11))
        printf("El jugador gana.");
    else {
        n++;
        first = a + b;
        printf("Ronda %d.\n", n);
        a = rand() % 6 + 1;
        b = rand() % 6 + 1;
        printf("Dado 1: %d\n", a);
        printf("Dado 2: %d\n", b);

        while((a+b!=first) && (a+b!=2) && (a+b!=12)) {
            n++;
            printf("Ronda %d.\n", n);
            a = rand() % 6 + 1;
            b = rand() % 6 + 1;
            printf("Dado 1: %d\n", a);
            printf("Dado 2: %d\n", b);
        }
        if(a + b == first)
            printf("El jugador gana.");
        else 
            printf("El jugador pierde.");
    }
}