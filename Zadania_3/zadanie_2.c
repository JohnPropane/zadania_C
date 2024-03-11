#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows = 10;
    int cols = 11;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc((cols) * sizeof(int));
    }

    srand(time(NULL));
    int r;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            r  = rand() % 100 + 1;
            matrix[i][j] = r;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free((int *)matrix[i]);
    }
    free(matrix);
    return 0;
}
