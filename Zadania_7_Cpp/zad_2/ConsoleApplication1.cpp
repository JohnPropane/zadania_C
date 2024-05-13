#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main()
{
    //Wczytanie pliku
    std::ifstream fptr("input.txt");
    if (!fptr) {
        std::cout << "Nie mozna odczytac pliku";
        return 1;
    }

    std::string myString;

    int games_power = 0;
    int data_on = 0;
    int game_num = 0;

    //Iteracja po każdej linii z pliku
    while (std::getline(fptr, myString)) {
        game_num++;

        //Ilość kości elfa
        int maxRed = 12;
        int maxBlue = 14;
        int maxGreen = 13;

        //Minimalna ilość kości potrzebna na gre
        int currRed = 0;
        int currBlue = 0;
        int currGreen = 0;

        //Iteracja po każdym znaku w linii
        for (int i = 0; i < myString.length(); i++) {

            //Sprawdzenie czy jesteśmy już po liczbie informującej o numerze gry
            if (myString[i] == ':') {
                data_on = 1;
            }

            //Szukanie liczby
            std::string number;
            if (data_on == 1) {
                if (isdigit(myString[i])) {
                    while (isdigit(myString[i])) {
                        number += myString[i];
                        i++;
                    }
                }

                //Sprawdzenie jaki kolor jest dla danej liczby
                if (myString[i + 1] == 'r' && myString[i + 2] == 'e' && myString[i + 3] == 'd') {
                    int num = std::stoi(number);
                    if (currRed < num) currRed = num;
                }
                else if (myString[i + 1] == 'b' && myString[i + 2] == 'l' && myString[i + 3] == 'u') {
                    int num = std::stoi(number);
                    if (currBlue < num) currBlue = num;
                }
                else if (myString[i + 1] == 'g' && myString[i + 2] == 'r' && myString[i + 3] == 'e') {
                    int num = std::stoi(number);
                    if (currGreen < num) currGreen = num;
                }
            }
        }

        //Obliczanie mocy
        games_power += currRed * currBlue * currGreen;
        data_on = 0;
        if (maxRed >= currRed && maxBlue >= currBlue && maxGreen >= currGreen) {
            std::cout << "Gra jest mozliwa do zagrania przez elfa\n";
        }
        else {
            std::cout << "Gra jest niemozliwa do zagrania przez elfa\n";
        }
        std::cout << "W grze nr." << game_num << " potrzebne jest " << currRed << " czerwona, " << currBlue << " niebieska, " << currGreen << " zielona kostkek, aby gra byla mozliwa\n";
        std::cout << "-------------------------------------------------------------------------\n";
    }
    std::cout << "Moc: " << games_power;
    return 0;
}
