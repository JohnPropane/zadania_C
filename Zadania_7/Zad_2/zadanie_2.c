#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    FILE* fptr;
    fptr = fopen("input.txt", "r");
    if (fptr == NULL){
        printf("Nie mozna odczytac pliku");
        return 1;
    }

    char myString[300];

    int data_on = 0;
    int game_num = 0;

    while(fgets(myString, 300, fptr)){
        game_num++;
        int maxRed = 12;
        int maxBlue = 14;
        int maxGreen = 13;

        int currRed = 0;
        int currBlue = 0;
        int currGreen = 0;

        for(int i = 0; i < strlen(myString); i++){
            if(myString[i] == ':'){
                data_on = 1;
            }

            char number[5];
            int counter = 0;
            if(data_on == 1){
                if(isdigit(myString[i])){
                    while(isdigit(myString[i])){
                        number[counter] = myString[i];
                        counter++;
                        i++;
                    }
                    number[counter] = '\0';
                }
            }

            if(myString[i+1] == 'r' && myString[i+2] == 'e' && myString[i+3] == 'd'){
                int num = atoi(number);
                if(currRed < num) currRed = num;
            }else if(myString[i+1] == 'b' && myString[i+2] == 'l' && myString[i+3] == 'u'){
                int num = atoi(number);
                if(currBlue < num) currBlue = num;
            }else if(myString[i+1] == 'g' && myString[i+2] == 'r' && myString[i+3] == 'e'){
                int num = atoi(number);
                if(currGreen < num) currGreen = num;
            }

        }
        data_on = 0;
        if(maxRed >= currRed && maxBlue >= currBlue && maxGreen >= currGreen){
            printf("Gra jest mozliwa do zagrania przez elfa\n");
        }else{
            printf("Gra jest niemozliwa do zagrania przez elfa\n");
        }
        printf("W grze nr.%d potrzebne jest %d czerwona, %d niebieska, %d zielona kostkek, aby gra byla mozliwa\n", game_num, currRed, currBlue, currGreen);
        printf("-------------------------------------------------------------------------\n");
    }

    fclose(fptr);
    return 0;
}
