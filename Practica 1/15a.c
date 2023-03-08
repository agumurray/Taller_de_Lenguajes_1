#include <stdio.h>

int factorial(int a);
int main() {
    int a;
    scanf("%d", &a);
    printf("%d", factorial(a));

    return 0;
}

int factorial(int a) {
    int i,res;
    res = 1;
    for (i=a; i>=1; i--) {
        res*=i;
    }
    return res;
}

