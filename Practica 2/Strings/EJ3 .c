#include <stdio.h>
#include <string.h>

char* swapChar(char[], char, char);

int main() {
    char string[] = "holasoyagustin";
    char char1 = 'o';
    char char2 = 'x';

    printf("String antes de ser procesado: %s \n", string);
    printf("Retorno de la funcion swapChar: %s \n", swapChar(string,char1,char2));
    printf("String luego de ser procesado: %s \n", string);

    return 0;
}

char* swapChar(char string[], char char1, char char2) {
    for(int i=0; i<strlen(string); i++) {
        if(string[i] == char1)
            string[i] = char2;
    }

    return string;
}

//no tiene sentido utilizar una funcion que retorne una cadena ya que un string, al ser un array unidimensional
// de caracteres, se envia como la direccion de memoria de la primer posicion a la funcion
// por lo tanto, cualquier modificacion que se realice dentro de la misma se vera reflejada en el main
// como cuando se envia una variable por referencia.