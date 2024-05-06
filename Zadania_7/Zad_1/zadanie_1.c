#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int str_to_int(char str[]){
    char numsStr[10][6] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i = 0; i < 10; i++){
        if(strcmp(str, numsStr[i]) == 0){
            return i;
        }
    }

}

void reverse_str(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int find_first_number(char str[]) {
    char numsStr[10][6] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < strlen(str); i++) {
        char newStr[100];
        strncpy(newStr, &str[0], i);
        newStr[i] = '\0';
        if(isdigit(newStr[i-1])){
                return newStr[i-1] - '0';
            }
        for(int j = 0; j < 10; j++){
            char* result = strstr(newStr, numsStr[j]);
            if(result != NULL){
                return str_to_int(numsStr[j]);
            }
        }
    }
}

int find_last_number(char str[]) {
    char numsStr[10][6] = {"orez", "eno", "owt", "eerht", "ruof", "evif", "xis", "neves", "thgie", "enin"};
    reverse_str(str);
    for (int i = 0; i < strlen(str)+1; i++) {
        char newStr[100];
        strncpy(newStr, &str[0], i);
        newStr[i] = '\0';
        if(isdigit(newStr[i-1])){
                return newStr[i-1] - '0';
            }
        for(int j = 0; j < 10; j++){
            char* result = strstr(newStr, numsStr[j]);
            if(result != NULL){
                char check[6];
                strcpy(check, numsStr[j]);
                reverse_str(check);
                return str_to_int(check);
            }
        }
    }
}

int main()
{

    FILE* fptr;
    fptr = fopen("input.txt", "r");

    char myString[100];
    int counter = 1;
    int sum_numbers = 0;
    int firstNumber = 0;
    int lastNumber = 0;

    while (fgets(myString, 100, fptr)) {
        firstNumber = find_first_number(myString);
        lastNumber = find_last_number(myString);
        sum_numbers += lastNumber + firstNumber;
        printf("%d. %d%d \n", counter, firstNumber, lastNumber);
        counter++;
    }

    printf("Sum of numbers: %d", sum_numbers);
    fclose(fptr);

}
