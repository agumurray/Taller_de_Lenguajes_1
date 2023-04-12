#include <stdio.h>

typedef enum { IZQUIERDA, CENTRO_H, DERECHA } AlineacionHorizontal; //enum correcto (0,1,2)
typedef enum { ARRIBA=1, CENTRO_V, ABAJO } AlineacionVertical; //enum correcto (1,2,3)
typedef enum { DOS=2, CERO=0, UNO, MENOS_UNO=-1, OTRO } Numeros; //enum correcto (2,0,1,-1,0)
//typedef enum { LET_A = "A", LET_B, LET_Z = "Z" } Letras; //enum incorrecto, un string no es un tipo de dato ordinal
typedef enum { LETRA_A = 'A', LETRA_B, LETRA_Z = 'Z' } Letras2; //enum correcto ('A', 'B', 'Z')

int main() {
    return 0;
}