#include <stdio.h>
#include <string.h>

int stringLength(char[]);

int main() {
    char string[] = "hola como estas.";

    printf("La longitud del string es: %d", stringLength(string));

    return 0;
}

int stringLength(char string[]){
    int i = 0;
    int counter = 0;
    while(string[i] != '\0') {
        counter++;
        i++;
    }
    return counter;
}