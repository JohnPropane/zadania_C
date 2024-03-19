#include <stdio.h>

unsigned int factorial(unsigned int x)
{
    if (x==0){
        return 1;
    }else if(x > 0){
        return x * factorial(x-1);
    }
    return 0;
}

int main() {
    printf("%d", factorial(5));
    return 0;
}
