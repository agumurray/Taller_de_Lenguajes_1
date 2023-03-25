#include <stdio.h>
#include <string.h>

int main() {
    char string[255];
    printf("Ingresa una palabra de menos de 255 caracteres: ");
    scanf("%s", string);
    int counter = 0;
    while(strcmp(string,"ZZZ") != 0) {
        if (strlen(string) == 5)
            counter++;
        printf("Ingresa una palabra de menos de 255 caracteres: ");
        scanf("%s", string);
    }

    printf("La cantidad de palabras de longitud 5 es: %d", counter);

    return 0;
}