#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/diccionario.h"

int main() {
    Diccionario* diccionario = crearDiccionario();

    // Agregar palabras al diccionario
    agregarPalabra(diccionario, "Hola");
    agregarPalabra(diccionario, "Mundo");
    agregarPalabra(diccionario, "Programacion");
    agregarPalabra(diccionario, "Diccionario");
    agregarPalabra(diccionario, "Verga");

    // Verificar si una palabra existe en el diccionario
    printf("Existe 'Hola' en el diccionario? %s\n", existePalabra(diccionario, "Hola") ? "Si" : "No");
    printf("Existe 'Adios' en el diccionario? %s\n", existePalabra(diccionario, "Adiós") ? "Si" : "No");

    // Eliminar una palabra del diccionario
    printf("Se elimino la palabra 'Hola'? %s\n", eliminarPalabra(diccionario, "Hola") ? "Si" : "No");

    // Cargar palabras desde un archivo
    cargarDesdeArchivo(diccionario, "palabras.txt");

    //Eliminar palabra
    eliminarPalabra(diccionario, "Verga");

    // Guardar el diccionario en un archivo
    cargarEnArchivo(diccionario, "diccionario.txt");


    // Imprimir el diccionario
    printf("Diccionario:\n");
    Palabra* actual = diccionario->primera;
    while (actual != NULL) {
        printf("%s\n", actual->palabra);
        actual = actual->siguiente;
    }

    // Destruir el diccionario
    destruirDiccionario(diccionario);

    return 0;
}