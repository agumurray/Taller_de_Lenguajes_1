#include <stdio.h>
int main(){
    char c= 'a';
    int x= 64;
    printf("char c= %c\n", x);  //%c hace que x sea procesado como un char. El 64 en el codigo ascii es 'a'
    printf("int x= %d\n", c);   //%d hace que c sea procesado como un entero. La a lleva el numero 97 en el codigo ascii
return 0;
}