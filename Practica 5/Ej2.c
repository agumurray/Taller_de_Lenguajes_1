#include <stdio.h>
#include <stdlib.h>
#define LONG 300

int main(){
    int minus, mayus, dig,i;
    minus = mayus = dig = 0;
    FILE *f;
    char linea[LONG];
    // Abrir el archivo
    f = fopen("textfiles/prueba.txt", "r");
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    while (fgets(linea, LONG, f) != NULL){
        i=0;
        while (linea[i] != '\n') {

            if((linea[i] >= 'A') && (linea[i]<='Z')) {
                mayus++;
            }
            else if ((linea[i] >= '0') && (linea[i]<='9')) {
                dig++;
            }
            else if ((linea[i] >= 'a') && (linea[i]<='z')) {
                minus++;
            }
            i++;
        }
    }
    fclose(f);
    printf("Mayusculas: %d\n Minusculas: %d\n Digitos: %d\n ", mayus, minus, dig);
    return 0;
}