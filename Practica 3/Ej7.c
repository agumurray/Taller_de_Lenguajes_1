#include <stdio.h>

struct estudiante {
  char apellido[50];
  char nombre[50];
  char legajo[8];
  int tipo; //1 argentinos - 2 extranjeros
  union identificacion {
    int dni;
    char pasaporte[20];
  } id;
};

int main() {
    struct estudiante e;

    printf("Ingrese el apellido del alumno: ");
    scanf("%s", e.apellido);
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", e.nombre);
    printf("Ingrese el legajo del alumno: ");
    scanf("%s",e.legajo);
    printf("El estudiante es argentino? (1 si - 2 no)");
    scanf("%d", &(e.tipo));
    if (e.tipo==1) {
        printf("Ingrese el dni del alumno argentino: ");
        scanf("%d", &(e.id.dni));
    }
    else {
        printf("Ingrese el pasaporte del alumno extranjero: ");
        scanf("%s", e.id.pasaporte);
    }

    printf("Nombre: %s\n", e.nombre);
    printf("Apellido: %s\n", e.apellido);
    printf("Legajo: %s\n", e.legajo);
    if (e.tipo==1) {
        printf("DNI: %d\n", e.id.dni);
    }
    else 
        printf("Pasaporte: %s\n", e.id.pasaporte);
    return 0;
}