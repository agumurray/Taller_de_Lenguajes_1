#include <stdio.h>

int es_primo(int a);
int main() {
    int a;

    scanf("%d", &a);
    a = (a<0) ? a*-1:a;

    if (es_primo(a) == 0) 
        printf("El numero NO es primo");
    else 
        printf("El numero es primo.");

    return 0;
}

int es_primo(int a) {
    int i;
    for (i=2;i<a;i++) {
        if (a%i == 0)
            return 0;
    }

    return 1;
}