#include <stdio.h>
#include <string.h>

int main() {
    int minusculas[26] = {0};
    int i;
    char string[] = "supercalifragilisticoespialidoso";

    for(i = 0; i<strlen(string); i++) 
        minusculas[string[i] - 97]++;

    for(i = 0; i<26; i++) {
        printf("Cantidad de letras [%c] en la palabra [%s] = %d \n", (97 + i), string, minusculas[i]);
    }
}