#include <stdio.h>

enum modulos {
    Bluetooth = 1,
    Wifi = 2,
    GPS = 4,
    Datos = 8,
    CamaraFrontal = 16,
    CamaraTrasera = 32,
    Linterna = 64,
    Vibrar = 128
};

const int  TODOS_LOS_MODULOS = 255;
const int  NINGUN_MODULO = 0;

void es_activo(int, int);
int main() {
    int modulos_activos = NINGUN_MODULO;

    // Marcar un módulo como activo
    modulos_activos |= Bluetooth;
    modulos_activos |= Wifi;

    es_activo(modulos_activos, Bluetooth);
    es_activo(modulos_activos, Wifi);

    // Marcar un módulo como inactivo
    modulos_activos &= ~Wifi;
    modulos_activos &= ~Bluetooth;

    es_activo(modulos_activos, Bluetooth);
    es_activo(modulos_activos, Wifi);

    // Invertir el estado actual de un modulo
    modulos_activos ^= Wifi;
    modulos_activos ^= Bluetooth;

    es_activo(modulos_activos, Wifi);
    es_activo(modulos_activos, Bluetooth);

    return 0;
}

void es_activo(int modulos_activos, int modulo) {
    if (modulos_activos & modulo) {
        printf("El modulo esta activo\n");
        printf("%d\n", modulos_activos);
    }
    else {
        printf("El modulo esta inactivo\n");
        printf("%d\n", modulos_activos);
    }
}


