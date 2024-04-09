#include <stdio.h>
#include <stdlib.h>

int add(int x, int y){
    return x + y;
}
int subtract(int x, int y){
    return x - y;
}

int multiply(int x, int y){
    return x * y;
}


int main()
{

    printf("Podaj pierwsza liczbe: ");
    int x;
    scanf("%d", &x);

    printf("Podaj druga liczbe: ");
    int y;
    scanf("%d", &y);

    printf("Wybierz dzialanie:\n\t1.dodawanie\n\t2.odejmowanie\n\t3.mnozenie\n");
    int choice;
    scanf("%d", &choice);

    int (*pf)(int, int);

    switch(choice){
    case 1:
        printf("\nDzialanie: %d + %d", x, y);
        pf=&add;
        break;
    case 2:
        printf("\nDzialanie: %d - %d", x, y);
        pf=&subtract;
        break;
    case 3:
        printf("\nDzialanie: %d * %d", x, y);
        pf=&multiply;
        break;
    default:
        printf("Error!");
        return 0;
    }

    printf("\nWynik: %d\n", (pf)(x, y));

    return 0;
}
