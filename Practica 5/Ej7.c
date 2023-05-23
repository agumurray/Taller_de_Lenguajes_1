#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main() {
    FILE *archivo_origen, *archivo_destino;
    char opcion;
    char buffer[MAX_BUFFER_SIZE];
    int caracter;
    int elementos_leidos;

    printf("¿Como desea copiar el archivo?\n");
    printf("1. Usando fgetc()\n");
    printf("2. Usando fgets()\n");
    printf("3. Usando fread()\n");
    printf("Ingrese su opcion: ");
    scanf(" %c", &opcion);

    archivo_origen = fopen("textfiles/ej7/original.txt", "r");
    archivo_destino = fopen("textfiles/ej7/copia.txt", "w");

    if (archivo_origen == NULL || archivo_destino == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    switch (opcion) {
        case '1':
            while ((caracter = fgetc(archivo_origen)) != EOF) {
                fputc(caracter, archivo_destino);
            }
            break;

        case '2':
            while (fgets(buffer, MAX_BUFFER_SIZE, archivo_origen) != NULL) {
                fputs(buffer, archivo_destino);
            }
            break;
        
        case '3':
            while ((elementos_leidos = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, archivo_origen)) > 0) {
                fwrite(buffer, sizeof(char), elementos_leidos, archivo_destino);
            }
            break;

        default:
            printf("Opción inválida.\n");
            return 1;
    }

    printf("Archivo copiado exitosamente.\n");

    fclose(archivo_origen);
    fclose(archivo_destino);

    return 0;
}