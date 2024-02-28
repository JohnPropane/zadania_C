#include <stdio.h>

int main()
{
    char name[50];
    printf("Podaj imie: ");
    scanf("%s", name);
    printf("Hello %s", name);

    return 0;
}