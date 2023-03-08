#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int res;
    int score = 0;

    int a,b;
    for (int i = 1; i<=4; i++) {
        a = rand() % 101;
        b = rand() % 101;

        printf("Calcule %d + %d", a, b);
        scanf("%d", &res);

        if (res == a + b)
            score++;
    }
    

    switch (score) {
        case 0 : printf("E");
        break;
        case 1 : printf("D");
        break;
        case 2 : printf("C");
        break;
        case 3 : printf("B");
        break;
        case 4 : printf("A");
    }
    return 0;
}
