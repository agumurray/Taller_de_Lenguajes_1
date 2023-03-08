#include <stdio.h>

int es_primo(int a);
int main() {
    int i,a;


    for (i=1;i<=5;i++) {
        scanf("%d", &a);
        if (es_primo(a)==0) 
            printf("El numero NO es primo\n");
        else
            printf("El numero es primo\n");
    }
}

int es_primo(int a) {
    int i;

    for(i=2;i<a;i++) {
        if (a%i == 0)
            return 0;
    }

    return 1;
}