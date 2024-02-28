#include <stdio.h>

void Silnia(int array[]) {
    for (int i = 0; i < 10; i++) {
        int silnia = 1;
        for (int j = 1; j < array[i]; j++) {
            silnia = silnia * j;
        }
        printf("!%d = %d \n", i, silnia);
    }
}


int main()
{
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Silnia(array);
    return 0;
}

