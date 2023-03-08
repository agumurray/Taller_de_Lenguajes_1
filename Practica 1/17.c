#include <stdio.h>

void max_min(int n, float *max, float *min);
int main() {
    int n;
    float max,min;

    scanf("%d", &n);
    max_min(n, &max, &min);

    printf("El maximo es: %f", max);
    printf("El minimo es: %f", min);
}

void max_min(int n, float *max, float *min) {
    float i;
    scanf("%f", &i);

    *max = i;
    *min = i;

    for (int j = 1; j < n; j++) {
        scanf("%f", &i);

        if (i > *max)
            *max = i;
        
        if (i < *min)
            *min = i;
    }
}