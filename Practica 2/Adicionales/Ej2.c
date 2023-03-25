#include <stdio.h>
#define CANT_DATOS 10

void opcion8(int *datos){
int i;
for (i=0; i<CANT_DATOS; i++){
*(datos+i)= datos[i]/2;
}
}

int main() {
    int datos[] = {2,4,6,8,10,12,14,16,18,20};

    opcion8(datos);

    for(int i=0; i<10; i++) {
        printf("%d \n", datos[i]);
    }

    return 0;
}