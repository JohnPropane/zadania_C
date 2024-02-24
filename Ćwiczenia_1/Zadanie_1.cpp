#include <iostream>
#include <stdio.h>

int main()
{
    char name[50];
    printf("Podaj imie: ");
    scanf_s("%s", name, (unsigned)_countof(name));
    printf("Hello %s", name);

    return 0;
}

