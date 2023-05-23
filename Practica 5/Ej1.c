#include <stdio.h>
#include <stdlib.h>
#define LONG 300

int main(){
    FILE *f;
    char linea[LONG];
    // Abrir el archivo
    f = fopen("textfiles/prueba.txt", "r");
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    //copia linea a vector linea, mueve puntero f al final de esa linea
    fgets(linea, LONG, f);
    while (!feof(f)){
        //imprime la linea
        puts(linea);
        //trae una nueva linea
        fgets(linea, LONG, f);
    }
    fclose(f);
    return 0;
}
