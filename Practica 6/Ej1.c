#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    printf("\nargc = %d",argc);
    printf("\nargv[0] => %s",argv[0]);
    return 0;
}

/*  Imprime: 
    argc = 1
    argv[0] = *ruta del programa*
    porque argc imprime el nro de argumentos pasados (solo ruta) y argv es el vector de argumentos
    y contiene solo la ruta del programa (argv[0]).
    
     */
