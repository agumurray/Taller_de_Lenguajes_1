#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 50; i++) {
        if (i % 5 == 0) {
            printf("%d", i);
            printf("\n");
        }
    }

    return 0;
}