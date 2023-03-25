#include <stdio.h>

int main(){
    int vector[10]={10,20,30,40,50,60,70,80,90,100};
    int i;
    int *p= vector;
    for (i=0; i<10; i++){
        *p += 3;
        printf("vector[%d] = %d \n", i, *p);
        p+=2;
    }
    return 0;
}

/*
a) Imprime 
vector[0] = 13
vector [1] = 23
vector[2] = 33
vector [3] = 43
vector [4] = 53
vector [5] = 63
vector [6] = 73
vector [7] = 83
vector [8] = 93
vector [9] = 103

b) La variable vector se ve modificada porque se incrementa el indice de forma correcta {i} y se incrementa cada valor desde un puntero
que tiene acceso a las celdas de cada posicion del vector. De todas formas, modificar los valores de un array de esta forma puede traer errores inesperados, por lo tanto, es conveniente modificarlos de la forma tradicional {v[i] = c}

c) Se imprimirian los mismos valores que con *p ya que estan siendo modificados con ese puntero.

d) nada, ya que p++ = p+=1

e) imprime los valores del vector cada dos posiciones incrementados en tres pero se pasa de la dimension logica y termina imprimiendo basura.
*/