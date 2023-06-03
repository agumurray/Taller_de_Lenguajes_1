#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0 

int main(){
    int x= 15;
    int y= 20;
    while (x<50){
        #if DEBUG
            printf("x= %d", x);
            y= y+1;
        #endif
        x++;
    }
    return 0;
}

//a)El codigo compila ya que el unico error no es compilado (no esta definido y)
//b)Si se cambia a 1 debug el codigo no compila ya que y no esta definido
//c)No es posible cambiar el valor de la constante simbólica DEBUG en tiempo de ejecución. Las constantes simbólicas se evalúan y se resuelven en tiempo de compilación. Por lo tanto, cualquier cambio en el valor de DEBUG requeriría recompilar el programa.
// Si se utiliza la directiva #ifdef en lugar de #if, el código dentro del bloque solo se compilará si la constante simbólica DEBUG está definida, independientemente de su valor. Por lo tanto, si se utiliza #ifdef DEBUG, el código dentro del bloque se compilará si DEBUG está definido, sin importar si su valor es 0 o 1.
//Si DEBUG está definido (independientemente de su valor), el código dentro del bloque #ifdef DEBUG se incluirá en el programa compilado. Si DEBUG no está definido, el código dentro del bloque se excluye del programa. En este caso, el valor de DEBUG no incide en el resultado de la compilación, solo determina si el bloque de código se incluirá o no en el programa final.
