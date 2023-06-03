#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1

int buscarElemento(int *vector, int longitud, int elemento) {
    #if DEBUG
    int accesos = 0;
    #endif

    for (int i = 0; i < longitud; i++) {
        #if DEBUG
        accesos++;
        #endif

        if (vector[i] == elemento) {
            #if DEBUG
            printf("Accesos: %d\n", accesos);
            #endif

            return i; // Se encontró el elemento, se retorna la posición
        }
    }

    #if DEBUG
    printf("Accesos: %d\n", accesos);
    #endif

    return -1; // No se encontró el elemento
}

int main() {
    srand(time(NULL)); // Inicializar la semilla aleatoria

    int longitud = 1000;
    int vector[longitud];

    // Generar vector de enteros al azar
    for (int i = 0; i < longitud; i++) {
        vector[i] = rand() % 1000;
    }

    int elemento;
    printf("Ingrese un numero a buscar: ");
    scanf("%d", &elemento);

    int posicion = buscarElemento(vector, longitud, elemento);

    if (posicion != -1) {
        printf("El numero %d se encuentra en la posicion %d\n", elemento, posicion);
    } else {
        printf("El numero %d no se encuentra en el vector\n", elemento);
    }

    return 0;
}

/*El tamaño del programa compilado puede diferir al activar o desactivar la depuración utilizando la constante simbólica DEBUG. Esto se debe a que cuando se habilita la depuración, se incluye código adicional para imprimir información en la consola, lo que aumenta el tamaño del programa. Cuando se deshabilita la depuración, ese código adicional se excluye del programa compilado, lo que reduce su tamaño. Por lo tanto, el tamaño del programa compilado puede ser mayor cuando la depuración está habilitada debido a la inclusión de código adicional relacionado con la depuración.*/