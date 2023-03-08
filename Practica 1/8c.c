#include <stdio.h>

int main() {
    int valor;
    scanf("%d",&valor);
    switch (valor % 2) {
        case 0: printf("El valor es par");
        break;
        case 1: printf("El valor es impar");
    }
}