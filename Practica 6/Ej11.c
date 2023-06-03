#include <stdio.h>
#include "lib/istack.h"

int main() {
    Stack* stack = s_create();

    int num;
    printf("Ingrese numeros enteros (0 para finalizar):\n");
    scanf("%d", &num);

    while (num != 0) {
        s_push(stack, num);
        scanf("%d", &num);
    }

    printf("\nElementos desapilados:\n");
    while (!s_empty(*stack)) {
        int element = s_pop(stack);
        printf("%d ", element);
    }
    printf("\n");

    free(stack->data);
    free(stack);

    return 0;
}