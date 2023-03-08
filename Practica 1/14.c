#include <stdio.h>

int invertir_numero(int i);
int main() {
    int i,a;

    scanf("%d", &i);
    printf("%d", invertir_numero(i));

    return 0;
}

int invertir_numero(int a) {
   int i = 0;

   while (a!=0) {
        i*=10;
        i+=a%10;
        a/=10;
   }

   return i;
}