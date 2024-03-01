#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char imie[20];
    float ocena;
}Student;

void sort(Student s[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (s[j].ocena < s[j + 1].ocena) {
                float temp = s[j].ocena;
                s[j].ocena = s[j + 1].ocena;
                s[j + 1].ocena = temp;
            }
        }
    }
};


int main()
{
    Student stud_array[4] = { {"Janek", 4.75}, {"Bartek", 5.0}, {"Pawel", 2.80}, {"Tobiasz", 3.79} };
    sort(stud_array, 4);
    for (int i = 0; i < 4; i++) {
        printf("%s: %.2f\n", stud_array[i].imie, stud_array[i].ocena);
    }

    return 0;
}