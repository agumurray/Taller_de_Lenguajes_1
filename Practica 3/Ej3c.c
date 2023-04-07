#include <stdio.h>

struct pun3D {
    float x,y,z;
};

typedef struct pun3D punto3D;

int main() {
    printf("%d\n", sizeof(struct pun3D)); //ocupa 12 bytes ya que cada float ocupa 4
    printf("%d\n", sizeof(punto3D)); //ocupa 12 bytes porque es una manera abreviada de llamar a struct pun3D

    punto3D arr[4];
    printf("%d", sizeof(arr)); //ocupa 48 bytes ya que se usan 12 variables floatantes. 12*4=48

    return 0;
}