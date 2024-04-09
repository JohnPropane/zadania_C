#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_array[10] = {0,1,2,3,4,5,6,7,8,9};
    int *array_pointer = &num_array;
    int i;
    for(i=0; i<10; i++){
        printf("Address = %x, number = %d\n", &num_array[i], *(array_pointer + i));
    }


    return 0;
}
