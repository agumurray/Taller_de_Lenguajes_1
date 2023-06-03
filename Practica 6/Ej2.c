#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Argumentos insuficientes o de mas.\n");
        return 1;
    }
    float promedio = 0;
    for (int i = 0; i < (argc - 1); i++) {
        promedio += (float) atoi(argv[i + 1]);
    }
    promedio /= (argc - 1);
    printf("El promedio es: %.2f\n", promedio);
    return 0;
}