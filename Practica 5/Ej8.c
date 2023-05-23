#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *txt = fopen("textfiles/ej8/numeros.txt", "w");
    FILE *bin = fopen("textfiles/ej8/numeros.dat", "wb");

    if ((txt==NULL) || (bin == NULL)) {
        printf("Uno de los dos archivos tuvo un problema al abrirse.\n");
        return 1;
    }

    int n;

    for (int i = 0; i<10; i++) {
        printf("Ingrese un numero del 0 al 9: ");
        scanf("%d", &n);
        fprintf(txt, "%d", n);
        fwrite(&n, sizeof(int),1, bin);
    }
    fclose(txt);
    fclose(bin);
    return 0;
}