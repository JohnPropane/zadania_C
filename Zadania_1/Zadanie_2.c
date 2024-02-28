#include <stdio.h>

int main()
{
    int grades[2][5] = { {2,4,5,5,2}, {2,5,5,5,1} };
    double srednia_matematyka = 0.0;
    double srednia_fizyka = 0.0;

    for (int i = 0; i < 5; i++) {
        srednia_matematyka += grades[0][i];
        srednia_fizyka += grades[1][i];
    }

    srednia_fizyka = srednia_fizyka / 5;
    srednia_matematyka = srednia_matematyka / 5;

    printf("Srednia z matematyki: %.2f\n", srednia_matematyka);
    printf("Srednia z fizyki: %.2f", srednia_fizyka);

    return 0;
}
