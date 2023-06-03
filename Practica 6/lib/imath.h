#ifndef IMATH_H
#define IMATH_H

int potencia(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

int cuadrado(int x) {
    return x * x;
}

int cubo(int x) {
    return x * x * x;
}

int absoluto(int i) {
    return i >= 0 ? i : -i;
}

int factorial(int i) {
    if (i == 0 || i == 1) {
        return 1;
    } else {
        int result = 1;
        for (int j = 2; j <= i; j++) {
            result *= j;
        }
        return result;
    }
}

int sumatoria(int i) {
    int result = 0;
    for (int j = 0; j <= i; j++) {
        result += j;
    }
    return result;
}

int multiplo(int x, int y) {
    return x % y == 0 ? 1 : 0;
}

int divisor(int x, int y) {
    return y % x == 0 ? 1 : 0;
}

int par(int i) {
    return i % 2 == 0 ? 1 : 0;
}

int impar(int i) {
    return i % 2 != 0 ? 1 : 0;
}

#endif
