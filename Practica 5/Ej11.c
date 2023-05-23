#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("textfiles/jugadores.dat", "rb+");
    fseek(f, 0, SEEK_END);
    long int tamanio = ftell(f);
    printf("El tamanio en bytes del archivo es: %ld", tamanio);
    return 0;
}
/*    -Alineación de estructuras: Los campos en una estructura pueden estar sujetos a requisitos de alineación impuestos por el compilador o el sistema operativo. Esto significa que los campos pueden ocupar más espacio en memoria de lo que se esperaría intuitivamente. Por ejemplo, aunque el campo int tiene un tamaño de 4 bytes, es posible que se requiera un alineamiento de 8 bytes en ciertos sistemas, lo que resultaría en un tamaño mayor para la estructura en general.

    -Padding o relleno: Algunos compiladores agregan bytes adicionales entre los campos de una estructura para mejorar el rendimiento o cumplir con requisitos de alineación. Estos bytes adicionales, conocidos como padding o relleno, pueden aumentar el tamaño total de la estructura y, por lo tanto, del archivo.

    -Metadatos del archivo: Es posible que el sistema operativo o el sistema de archivos agreguen ciertos metadatos al archivo, como información de fecha y hora de creación, permisos de archivo, tamaño de bloque utilizado por el sistema de archivos, entre otros. Estos metadatos pueden aumentar el tamaño total del archivo.
*/