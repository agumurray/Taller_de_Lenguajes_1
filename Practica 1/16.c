#include <stdio.h>

void swap(int a, int b);

int main() {
    int x, y;
    x = 10;
    y = 20;
    printf("x=%d\ty=%d\n",x,y);
    swap(x, y);
    printf("x=%d\ty=%d\n",x,y);
    return 0; 
}

void swap(int a, int b) {  //los valores solo se modifican dentro de la funcion. 
                          //deben utilizarse parametros de entrada y salida (referencias) no vistos aun.
    int tmp;

    tmp = a;
    a = b;
    b = tmp;
}