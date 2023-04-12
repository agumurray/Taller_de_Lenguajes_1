#include <stdio.h>
#include <string.h>
#include <time.h>

struct fecha {
    int tipo;
    union {
        time_t f_unix;
        char f_texto[11];
    } datos_fecha;
};

int compare (struct fecha, struct fecha);

int main() {
    struct fecha f1;
    struct fecha f2;

    f1.tipo=1;
    f1.datos_fecha.f_unix = time(NULL);

    f2.tipo=2;
    strcpy(f2.datos_fecha.f_texto,"11/04/2023");


    if (!(compare(f1,f2))) {
        printf("Las fechas son iguales.");
    }
    else {
        printf("Las fechas son distintas");
    }

    return 0;
}

int compare (struct fecha f1, struct fecha f2) {
    if (f1.tipo == f2.tipo) {
        if (f1.tipo == 1) 
            return (f1.datos_fecha.f_unix == f2.datos_fecha.f_unix);
        else 
            return (strcmp(f1.datos_fecha.f_texto,f2.datos_fecha.f_texto));
    }
    struct tm *struct_tm;
    char aux[11];
    if (f1.tipo == 1) {
        struct_tm = localtime(&f1.datos_fecha.f_unix);
        strftime(aux, sizeof(aux), "%d/%m/%Y", struct_tm);
        return strcmp(aux,f2.datos_fecha.f_texto);
    }
    else {
        struct_tm = localtime(&f2.datos_fecha.f_unix);
        strftime(aux,sizeof(aux), "%d/%m/%Y", struct_tm);
        return strcmp(aux,f1.datos_fecha.f_texto);
    }
}

/* funcionaria de manera distinta en cada caso ya que en uno el anio seria el primer dato y en el otro el ultimo y viceversa
deberia manipularse dicho error y controlarlo*/