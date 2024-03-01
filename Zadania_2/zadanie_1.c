#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a;
    a = 10;
    int* pointer = &a;
    *pointer += 1;
    printf("%d\n", a);
    printf("%d", *pointer);

    return 0;
}