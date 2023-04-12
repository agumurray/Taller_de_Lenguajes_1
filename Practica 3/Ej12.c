#include <stdio.h>

struct RGB24 {
    unsigned red : 8;
    unsigned green : 8;
    unsigned blue : 8;
};

struct RGB16 {
    unsigned red : 5;
    unsigned green : 6;
    unsigned blue : 5;
};

struct RGB24 _16to24(struct RGB16);
struct RGB16 _24to16(struct RGB24);
int main() {
    struct RGB24 rgb24;
    rgb24.red = 13;
    rgb24.green = 255;
    rgb24.blue = 125;
    printf("RED = %d == GREEN = %d == BLUE = %d\n", rgb24.red,rgb24.green,rgb24.blue);

    struct RGB16 rgb16 = _24to16(rgb24);
    printf("RED = %d == GREEN = %d == BLUE = %d\n", rgb16.red,rgb16.green,rgb16.blue);

    rgb24 = _16to24(rgb16);
    printf("RED = %d == GREEN = %d == BLUE = %d\n", rgb24.red,rgb24.green,rgb24.blue);

    return 0;
}

struct RGB16 _24to16(struct RGB24 rgb) {
    struct RGB16 rgb16;
    if (rgb.red > 31)
        rgb16.red = 31;
    else
        rgb16.red = rgb.red;

    if (rgb.green > 63) 
        rgb16.green = 63;
    else 
        rgb16.green = rgb.green;
    if (rgb.blue > 31)
        rgb16.blue = 31;
    else 
        rgb16.blue = rgb.blue;
    return rgb16;
}


struct RGB24 _16to24(struct RGB16 rgb) {
    struct RGB24 rgb24;
    rgb24.red = rgb.red;
    rgb24.green = rgb.green;
    rgb24.blue = rgb.blue;
    return rgb24;
}