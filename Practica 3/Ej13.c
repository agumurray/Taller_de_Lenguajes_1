#include <stdio.h>

struct modulos {
    unsigned Bluetooth : 1;
    unsigned Wifi : 1;
    unsigned GPS : 1;
    unsigned Datos : 1;
    unsigned Frontal : 1;
    unsigned Trasera : 1;
    unsigned Linterna : 1;
    unsigned Vibrar : 1;
};

int main() {
    struct modulos estado_modulos;

    //marcar modulo como activo:
    estado_modulos.Wifi = 1;

    //marcar modulo como inactivo:
    estado_modulos.Wifi = 0;

    //invertir el estado actual de un modulo:
    estado_modulos.Wifi = ~estado_modulos.Wifi;


    //determinar si un modulo esta activo
    if (estado_modulos.Wifi == 1)
        printf("El modulo esta activo");
    else
        printf("El modulo esta inactivo");

    return 0;
}