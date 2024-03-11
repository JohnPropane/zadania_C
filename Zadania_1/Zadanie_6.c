#include <stdlib.h>
#include <stdio.h>

//Przetłumaczenie ruchu np. 1 na Kamień, 2 na Nożyce etc.
void move(int gracz) {
    switch (gracz) {
    case 1:
        printf("Kamien ");
        break;
    case 2:
        printf("Nozyce ");
        break;
    case 3:
        printf("Papier ");
        break;
    default:
        printf("Podano niepoprawne wartosci! ");
    }
}

//Funkcja sprawdzająca wynik rundy
int show_result(int p1, int p2) {
    if ((p1 > 3 || p1 < 1) || (p2 > 3 || p2 < 1)) {
        printf("Podano niepoprawne opcje!\n");
        return 0;
    }
    else if (p1 == p2) {
        printf("REMIS!\n");
        return 3;
    }
    else if (p1 == 1 && p2 == 2) {
        printf("Wygrywa gracz 1\n");
        return 1;
    }
    else if (p1 == 2 && p2 == 1) {
        printf("Wygrywa gracz 2\n");
        return 2;
    }
    else if (p1 == 3 && p2 == 1) {
        printf("Wygrywa gracz 1\n");
        return 1;
    }
    else if (p1 == 1 && p2 == 3) {
        printf("Wygrywa gracz 2\n");
        return 2;
    }
    else if (p1 == 3 && p2 == 2) {
        printf("Wygrywa gracz 2\n");
        return 2;
    }
    else if (p1 == 2 && p2 == 3) {
        printf("Wygrywa gracz 1\n");
        return 1;
    }
    else {
        printf("Podano niepoprawne opcje!\n");
        return 0;
    }
}

//Funkcja printująca historie rund
void read_history(int rounds_info[10][3], int runda) {
    printf("\nHistoria:\n");
    if (runda < 1) {
        printf("Brak danych\n");
    }
    else {
        for (int i = 0; i < runda; i++) {
            printf("Runda %d:", i+1);
            move(rounds_info[i][0]);
            printf("vs ");
            move(rounds_info[i][1]);
            show_result(rounds_info[i][0], rounds_info[i][1]);
        }
    }
    printf("\n");
}

int main()
{
    //int i;
    //scanf("%d", &i);
    //printf("%d", i);

    int num_of_rounds = 10;
    int rounds_info[11][3]; //[runda][ruch gracza 1, ruch gracza 2, wynik]

    int p1_score = 0;
    int p2_score = 0;

    printf("Witaj w grze papier, kamien, nozyce\n");
    printf("Mozliwe opcje:\n\tKamien = 1\n\tNozyce = 2\n\tPapier = 3\nHistoria gry = 4\n");

    for (int i = 0; i < num_of_rounds; i++) {
        printf("Runda %d/%d: \n", i + 1, num_of_rounds);

        int p1;
        printf("Ruch gracza 1: \n");
        scanf("%d", &p1);
        rounds_info[i][0] = p1;

        if (p1 == 4) {
            read_history(rounds_info, i);
            i--;
        }
        else {
            int p2;
            printf("Ruch gracza 2: \n");
            scanf("%d", &p2);
            rounds_info[i][1] = p2;

            move(p1);
            printf("vs ");
            move(p2);
            printf("\n");

            int result = show_result(p1, p2);
            rounds_info[i][2] = result;
            switch (result) {
            case 1:
                p1_score++;
                break;
            case 2:
                p2_score++;
                break;
            case 3:
                p1_score++;
                p2_score++;
                break;
            case 0:
                i--;
                break;
            }

            printf("\nPunktacja: Gracz 1: %d | Gracz 2: %d\n", p1_score, p2_score);
        }
    }
    printf("Koniec gry!\n");
    if (p1_score == p2_score) {
        printf("Remis");
    }
    else if (p1_score > p2_score) {
        printf("Wygrywa gracz 1\n");
    }
    else {
        printf("Wygrywa gracz 2\n");
    }

    read_history(rounds_info, num_of_rounds);

    return 0;
}

