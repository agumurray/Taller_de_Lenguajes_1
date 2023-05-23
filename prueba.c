#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "hola";
    char b[] = "hola";
    char c[] = "chau";

    printf("Esto imprime strcmp para strings iguales: %d\n", strcmp(a,b));
    printf("%d\n", strcmp(a,c));
    printf("%d\n", strcmp(c,a));
    return 0;
}