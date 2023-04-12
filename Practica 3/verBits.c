#include <stdio.h>

void verBits( unsigned );
int main()
{
  unsigned x;

  printf("Ingrese un entero sin signo: ");
  scanf("%u", &x);

  verBits(x);

  return 0;
}

void verBits(unsigned valor){
    // Obtener el tamaño en bits de un unsigned
    int tamano = sizeof(unsigned) * 8;

    // Crear una máscara con el bit más significativo en 1
    unsigned mascara = 1 << (tamano - 1);

    printf("%10u = ", valor);

    // Iterar sobre cada bit
    int j = 0;
    for (int i = 0; i < tamano; ++i) {
        // Imprimir el bit actual
        printf("%c", (valor & mascara) ? '1' : '0');
        if (j == 4) { 
            printf(" ");
            j = 0;
        }
        j++;
        // Desplazar la máscara un bit a la derecha
        mascara >>= 1;
    }

    printf("\n");
}





