#include <stdio.h>

int factorial(int a);
int main() {
    int a;
    scanf("%d", &a);
    printf("%d", factorial(a));
}

int factorial(int a) {
    if (a==1)
        return 1;
    else 
        return(a * factorial(a-1));
}