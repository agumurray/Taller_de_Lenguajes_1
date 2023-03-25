#include <stdio.h>
#include <string.h>

void upperStr(char[]);
void lowerStr(char[]);
char* numToStr(char[], int);
char* numToText(char[], int);

int main() {
    char string[] = "hOlaComoEstas";

    printf("[%s] \n", string);    
    upperStr(string);
    printf("[%s] \n", string);
    lowerStr(string);
    printf("[%s] \n", string);

    char numero[10];

    printf("[%s]", numToStr(numero, 27345724));

    printf("Ingrese un numero del 0 al 99: \n");
    int num;
    scanf("%d", &num);
    char cadena[100];
    printf("%s", numToText(cadena, num));

    return 0;
}

void upperStr(char string[]) {
    int i = 0;
    while(string[i] != '\0') {
        if ((string[i]<=122) && (string[i]>=97))
            string[i] -= 32;
        i++;
    }
}

void lowerStr(char string[]) {
    int i = 0;
    while(string[i] != '\0') {
        if ((string[i]<=90) && (string[i]>=65))
            string[i] += 32;
        i++;
    }
}

char* numToStr(char numero[], int n) {
    int len = 0;
    int x = n;
    while (x != 0) {
        len++;
        x /= 10;
    }


    numero += len - 1;

    while (n != 0) {
        *numero = n % 10 + '0';
        numero--;
        n /= 10;
    }

    numero += len + 1;
    *numero = '\0';
    numero -= len;

    return numero;
}

char* numToText(char cadena[], int num) {
    char* text[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete","dieciocho" ,"diecinueve"};

    char* text1[] = {"veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta","noventa"};
    if(num<20) {
        strcpy(cadena,text[num]);
    }
    else if(num<30) {
        if (num == 20)
            strcpy(cadena, text1[0]);
        else {
            strcpy(cadena, "veinti");
            strcat(cadena, text[num%10]);
        }
    }
    else if(num>30) {
        if (num % 10 == 0)
            strcpy(cadena, text1[num]);
        else {
            strcpy(cadena, text1[num/10 -2]);
            strcat(cadena, " y ");
            strcat(cadena, text[num%10]);
        }
    }

    return cadena;
}