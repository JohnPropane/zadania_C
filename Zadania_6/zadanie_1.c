#include <stdio.h>
#include <stdlib.h>

union zadanie_1{
    int theInt;
    float theFloat;
    char theChar;
};

int main()
{
    union zadanie_1 test;
    test.theInt = 5;
    printf("Int = %d\n", test.theInt);

    test.theFloat = 2.2;
    printf("Float = %f\n", test.theFloat);

    test.theChar = 's';
    printf("Char = %c\n", test.theChar);

    return 0;
}
