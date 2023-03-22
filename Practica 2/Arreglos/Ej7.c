#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menorLluviaMes(int[30][12][10], int);
int menorPrecProm(int[30][12][10]);

int main() {
    srand(time(NULL));

    int lluvia[30][12][10];

    int d,m,a;

    for(a=0; a<10; a++) {
        for(m=0; m<12; m++) {
            for(d=0; d<30; d++) {
                lluvia[d][m][a] = rand() % 200 + 1;
            }
        }
    }

    for (a=0; a<10; a++) {
        printf("El mes en el que menos llovio en el anio %d fue: %d \n",a, menorLluviaMes(lluvia, a));
    }

    printf("El anio con menor precipitacion promedio es: %d", menorPrecProm(lluvia));

    return 0;
}

int menorLluviaMes(int lluvia[][12][10], int a) {
   int lluviaMes = 0;
   int lluviaMin = __INT_MAX__;
   int mesMin;
   for(int m=0; m<12; m++) {
    for(int d=0; d<30; d++) {
        lluviaMes+=lluvia[d][m][a];
    }
        if (lluviaMes<lluviaMin) { 
            lluviaMin = lluviaMes;
            mesMin = m;
   }
    lluviaMes=0;
   }
   
   return mesMin;
}

int menorPrecProm(int lluvia[][12][10]) {
     int d,m,a;
     int contLluvia = 0;
     int lluviaPromMin = __INT_MAX__;
     int anioMenor;
     for(a=0; a<10; a++) {
        for(m=0; m<12; m++) {
            for(d=0; d<30; d++) {
                contLluvia += lluvia[d][m][a];
            }
        }
        if((contLluvia/360)<lluviaPromMin) {
            lluviaPromMin = contLluvia/360;
            anioMenor = a;
        }
        contLluvia = 0;
    }
    return anioMenor;
}