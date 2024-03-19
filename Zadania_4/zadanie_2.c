#include <stdio.h>

unsigned int binarySearch(unsigned int *array, unsigned int left, unsigned int right, unsigned int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (array[mid] == x){
            return mid;
        }
        else if (array[mid] > x){
            return binarySearch(array, left, mid - 1, x);
        }else{
            return binarySearch(array, mid + 1, right, x);
        }
    }
    return -1;
}

int main() {
    int array[] = {2, 3, 4, 10, 40};
    int array_size = sizeof(array) / sizeof(array[0]);
    int x = 10;

    printf("%d", binarySearch(&array[0], 0, array_size-1, x));

    return 0;
}
