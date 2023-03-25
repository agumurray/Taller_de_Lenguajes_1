#include <stdio.h>
#include <string.h>

int main() {
    char string[255];
    printf("Ingrese una palabra de hasta 255 caracteres: ");
    scanf("%s", string);

    int counter = 0;

    while(strcmp(string,"XXX") != 0) {
        if (string[strlen(string) - 1] == 'o') 
            counter++;
        printf("Ingrese una palabra de hasta 255 caracteres: ");
        scanf("%s", string);
    }

    printf("La cantidad de palabras terminadas en 'o' es: %d", counter);

    return 0;
}