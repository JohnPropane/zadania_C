#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 10;

    int** pascal = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        pascal[i] = (int*)malloc((i + 1) * sizeof(int));
    }

    if (rows >= 1) {
        pascal[0][0] = 1;
    }

    if (rows >= 2) {
        pascal[0][0] = 1;
        pascal[1][0] = 1;
        pascal[1][1] = 1;
    }

    if(rows >= 3) {
        for (int i = 2; i < rows; i++) {
            for (int j = 0; j < i+1; j++) {
                if (j == 0 || j == i) {
                    pascal[i][j] = 1;
                }
                else {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free((int *)pascal[i]);
    }
    free(pascal);

    return 0;
}


