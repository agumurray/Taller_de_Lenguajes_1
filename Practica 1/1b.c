#include <stdio.h>
int main(){
    int x=10;
    if (x==5) // error, no se comparaba. se asignaba un valor a la variable que, segun C es verdadero. El programa no cumplia con su funcion original.
        printf("x = 5\n");
    return 0;
}