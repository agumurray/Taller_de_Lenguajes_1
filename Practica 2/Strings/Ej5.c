#include <stdio.h>
#include <string.h>

void stringCopy(char[], char[]);

int main() {
    char string1[] = "hola como estas... ncahsssseh";
    char string2[] = "andate a la mierda";

    printf("String1 antes de ser procesado: %s \n", string1);
    stringCopy(string1,string2);
    printf("String1 luego de ser procesado: %s", string1);

    return 0;
}

void stringCopy(char string1[], char string2[]) {
    int i = 0;
    while(string2[i] != '\0') {
        string1[i] = string2[i];
        i++;
    }
    string1[i] = '\0';
}