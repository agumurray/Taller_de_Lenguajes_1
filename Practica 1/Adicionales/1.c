#include <stdio.h>

int main() {
    int minQuant1,minQuant2,minCode1,minCode2,quant40,code,quant;
    float per;

    quant40 = 0;
    minQuant1 = 9999999;

    for(int i=1; i<=4; i++) {
        printf("Ingrese el codigo de pais: ");
        scanf("%d", &code);
        printf("Ingrese la cantidad de especies: ");
        scanf("%d", &quant);
        
        if (quant<minQuant1) {
            minQuant2 = minQuant1;
            minCode2 = minCode1;

            minCode1 = code;
            minQuant1 = quant;
        }
        else {
            if (quant<minQuant2) {
                minQuant2 = quant;
                minCode2 = code;
            }
        }
            
        if(quant>40)
            quant40++;
    }

    printf("El codigo del pais con menos especies es: %d y tiene %d especies.\n", minCode1,minQuant1);
    printf("El codigo del segundo pais con menos especies es: %d y tiene %d especies.\n", minCode2,minQuant2);
    printf("El porcentaje de paises con mas de 40 especies es: %f porciento.", ((float) quant40 / 4) * 100 );

    return 0;

}