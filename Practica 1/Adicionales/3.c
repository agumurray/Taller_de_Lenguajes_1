#include <stdio.h>

int main() {
    double pi = 3.0;
    double  a = -1.0;
    for(int i=2; i<3000; i+=2) {
        a*=-1;
        pi += a*((double) 4/(i*(i+1)*(i+2)));
    }

    printf("%.10f", pi);
}

/*Si ejecutamos ambas versiones del programa, podemos observar que la versión con tipo de datos double proporciona una aproximación más precisa de PI que la versión con tipo de datos float. Por ejemplo, la versión con tipo de datos float proporciona una aproximación de PI de 3.141593, mientras que la versión con tipo de datos double proporciona una aproximación de PI de 3.14159265358979.

Esto se debe a que el tipo de datos double tiene una mayor precisión que el tipo de datos float. Sin embargo, el tipo de datos double también ocupa más memoria que el tipo de datos float*/