#include <stdio.h>
#include <stdlib.h>
#define LONG 300

struct atributosVino{
    float acidez_fija;
    float acidez_volatil;
    float acido_citrico;
    float azucares;
    float ph;
    float sulfatos;
    float alcohol;
    float calidad;
};

int main() {
    struct atributosVino total = {0,0,0,0,0,0,0,0};
    struct atributosVino actual;
    struct atributosVino max = {-1,-1,-1,-1,-1,-1,-1,-1};
    struct atributosVino min = {1000,1000,1000,1000,1000,1000,1000,1000};
    struct atributosVino promedio;
    FILE *f = fopen("textfiles/vinos.csv" ,"r");
    if (f==NULL) {
        printf("Error al abrir archivo .csv.\n");
        return 1;
    }
    int cantLineas = 0;
    char linea[LONG];
    char tipo[LONG];
    fgets(linea, LONG, f);
    printf("%s", linea);
    while(!feof(f)) {
        fscanf(f, "%f;%f;%f;%f;%f;%f;%f;%f;%s", &actual.acidez_fija, &actual.acidez_volatil, &actual.acido_citrico, &actual.azucares, &actual.ph, &actual.sulfatos, &actual.alcohol, &actual.calidad, tipo);
        total.acidez_fija += actual.acidez_fija;
        total.acidez_volatil += actual.acidez_volatil;
        total.acido_citrico += actual.acido_citrico;
        total.azucares += actual.azucares;
        total.ph += actual.ph;
        total.sulfatos += actual.sulfatos;
        total.alcohol += actual.alcohol;
        total.calidad += actual.calidad;

        if (actual.acidez_fija > max.acidez_fija) max.acidez_fija = actual.acidez_fija;
        if (actual.acidez_volatil > max.acidez_volatil) max.acidez_volatil = actual.acidez_volatil;
        if (actual.acido_citrico > max.acido_citrico) max.acido_citrico = actual.acido_citrico;
        if (actual.azucares > max.azucares) max.azucares = actual.azucares;
        if (actual.ph > max.ph) max.ph = actual.ph;
        if (actual.sulfatos > max.sulfatos) max.sulfatos = actual.sulfatos;
        if (actual.alcohol > max.alcohol) max.alcohol = actual.alcohol;
        if (actual.calidad > max.calidad) max.calidad = actual.calidad;

        if (actual.acidez_fija < min.acidez_fija) min.acidez_fija = actual.acidez_fija;
        if (actual.acidez_volatil < min.acidez_volatil) min.acidez_volatil = actual.acidez_volatil;
        if (actual.acido_citrico < min.acido_citrico) min.acido_citrico = actual.acido_citrico;
        if (actual.azucares < min.azucares) min.azucares = actual.azucares;
        if (actual.ph < min.ph) min.ph = actual.ph;
        if (actual.sulfatos < min.sulfatos) min.sulfatos = actual.sulfatos;
        if (actual.alcohol < min.alcohol) min.alcohol = actual.alcohol;
        if (actual.calidad < min.calidad) min.calidad = actual.calidad;

        cantLineas++;
    }
    promedio.acidez_fija = total.acidez_fija / cantLineas;
    promedio.acidez_volatil = total.acidez_volatil / cantLineas;
    promedio.acido_citrico = total.acido_citrico / cantLineas;
    promedio.azucares = total.azucares / cantLineas;
    promedio.ph = total.ph / cantLineas;
    promedio.sulfatos = total.sulfatos / cantLineas;
    promedio.alcohol = total.alcohol / cantLineas;
    promedio.calidad = total.calidad / cantLineas;

    fclose(f);

    f = fopen("textfiles/reporte_vinos.txt", "w");
    if (f==NULL) {
        printf("Error al abrir archivo de reporte.\n");
        return 1;
    }
    fprintf(f, "Atributo;Maximo;Minimo;Promedio\n");
    fprintf(f, "Acidez fija;%.2f;%.2f;%.2f\n", max.acidez_fija, min.acidez_fija, promedio.acidez_fija);
    fprintf(f, "Acidez volatil;%.2f;%.2f;%.2f\n", max.acidez_volatil, min.acidez_volatil, promedio.acidez_volatil);
    fprintf(f, "Acido citrico;%.2f;%.2f;%.2f\n", max.acido_citrico, min.acido_citrico, promedio.acido_citrico);
    fprintf(f, "Azucares;%.2f;%.2f;%.2f\n", max.azucares, min.azucares, promedio.azucares);
    fprintf(f, "pH;%.2f;%.2f;%.2f\n", max.ph, min.ph, promedio.ph);
    fprintf(f, "Sulfatos;%.2f;%.2f;%.2f\n", max.sulfatos, min.sulfatos, promedio.sulfatos);
    fprintf(f, "Alcohol;%.2f;%.2f;%.2f\n", max.alcohol, min.alcohol, promedio.alcohol);
    fprintf(f, "Calidad;%.2f;%.2f;%.2f\n", max.calidad, min.calidad, promedio.calidad);
    fclose(f);
    return 0;
}

//claramente no es la solucion mas legible ni eficiente pero no me importa.