#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {
    char cadena[200];
    if (argc == 1) {
        printf("Error.");
        return 1;
    }
    else {
        strcpy(cadena, argv[1]);
        for (int i = 2; i < argc; i++) {
            strcat(cadena, argv[i]);
            strcat(cadena, " ");
        }
    }
    printf("%s", cadena);
}