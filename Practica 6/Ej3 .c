#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Debes proporcionar dos números enteros y un operador.\n");
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    char operador = argv[3][0];
    int resultado;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %d + %d = %d\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: %d - %d = %d\n", num1, num2, resultado);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: No se puede dividir por cero.\n");
                return 1;
            }
            resultado = num1 / num2;
            printf("Resultado: %d / %d = %d\n", num1, num2, resultado);
            break;
        case '.':
            resultado = num1 * num2;
            printf("Resultado: %d * %d = %d\n", num1, num2, resultado);
            break;
        default:
            printf("Error: Operador inválido. Los operadores válidos son: +, -, /, .\n");
            return 1;
    }

    return 0;
}