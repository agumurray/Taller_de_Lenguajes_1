#include <stdio.h>

union dimensiones {
    struct {
        unsigned x,y,ancho,alto;
    } forma1;

    struct {
        struct {
            unsigned x1,y1;
        };

        struct {
            unsigned x2,y2;
        };
    } forma2;

    struct {
        struct {
            unsigned x,y;
        };
        
        struct {
            unsigned ancho,alto;
        };
    } forma3;
};