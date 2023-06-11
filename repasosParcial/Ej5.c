#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct destino{
     int codProv;
     int codLoc;
     char nomLoc[30];
     int nHab;
};

int main() {
     FILE* txt = fopen("Habitantes.txt", "r");
     FILE* dat = fopen("Habitantes.dat", "wb+");

     struct destino act; 
     struct destino max = {0, 0, " ", -1};

     while (fscanf(txt, "%d %d %s %d\n", &(act.codProv), &(act.codLoc), act.nomLoc, &(act.nHab)) == 4) {

          fwrite(&act, sizeof(act), 1, dat);
     }

     fseek(dat, 0, SEEK_SET);

     while ((fread(&act, sizeof(act), 1, dat)) > 0) {
          if (act.nHab > max.nHab) {
               max = act;
          }
     }
     printf("Localidad con mayor cantidad de habitantes:\n");
     printf("Nombre: %s \n Codigo: %d", max.nomLoc, max.codLoc);
     return 0;
}