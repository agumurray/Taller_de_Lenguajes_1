#include <stdio.h>

int suma(int n);
int main() {
    int n;
    scanf("%d", &n);

    while (n!=0) {
        printf("<<<");
        while(n/10 != 0) {
            printf("%d => ", n);
            n = suma(n);
        }
        printf("%d>>>\n", n);
        scanf("%d", &n);
    }

    return 0;
}

int suma(int n) {
    int res = 0;
    while(n != 0) {
        res += n % 10;
        n /= 10;
    }

    return (res);
}