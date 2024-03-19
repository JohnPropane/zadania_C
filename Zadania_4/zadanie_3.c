#include <stdio.h>

void permute(int *array, int start, int end) {
    if (start == end) {
        for(int i = 0; i <= end; i++)
            printf("%d ", array[i]);
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            int temp = array[start];
            array[start] = array[i];
            array[i] = temp;

            permute(array, start+1, end);

            temp = array[start];
            array[start] = array[i];
            array[i] = temp;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    permute(arr, 0, n-1);
    return 0;
}

