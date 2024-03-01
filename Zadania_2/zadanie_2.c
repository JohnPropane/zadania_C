#include <stdlib.h>
#include <stdio.h>

void multipleby2(float * x) {
    (*x)*=2;
}

int main()
{
    float x = 5.0;
    printf("Przed: %f\n", x);
    multipleby2(&x);
    printf("Po: %f", x);
    return 0;
}