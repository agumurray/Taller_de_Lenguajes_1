#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    srand(time(NULL));
    for (int i = 1; i <= 15; i ++) {
        n = rand();
        printf("%d ", n );
    }

    return 0;
}