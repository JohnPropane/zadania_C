#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    char surname[30];
    char phone_number[9];
}Contact;

void add_contact(Contact c[10], int* index) {
    Contact cont;
    printf("Podaj imie: \n");
    scanf("%s", cont.name);
    printf("Podaj nazwisko: \n");
    scanf("%s", cont.surname);
    printf("Podaj numer telefonu: \n");
    scanf("%s", cont.phone_number);
    (c)[*index] = cont;
    (*index)++;
}

void del_contact(Contact c[], int* index) {
    char surname[30];
    Contact con;
    printf("Podaj nazwisko do usuniecia: ");
    scanf("%s", con.surname);
    for (int i = 0; i < 10; i++) {
        if (strncmp((c)[i].surname, con.surname, 30) == 0) {
            for (int j = i; j < 10; j++) {
                (c)[j] = (c)[j + 1];
            }
            break;
        }
    }
    (*index)--;
    printf("Pomyslnie usunieto\n\n");
}

void read_contacts(Contact contact[], int index) {
    for (int i = 0; i < index; i++) {
        printf("Kontakt %d:\n", i + 1);
        printf("Imie: %s\n", contact[i].name);
        printf("Nazwisko: %s\n", contact[i].surname);
        printf("Numer: %s\n", contact[i].phone_number);
        printf("-----------------------------------------\n");
    }
}

void search_contact(Contact contact[], int index) {
    printf("Podaj nazwisko do wszukania: \n");
    char surname[30];
    Contact con;
    scanf("%s", con.surname);
    for (int i = 0; i < index; i++) {
        if (strncmp((contact)[i].surname, con.surname, 30) == 0) {
            printf("Kontakt %d:\n", i + 1);
            printf("Imie: %s\n", contact[i].name);
            printf("Nazwisko: %s\n", contact[i].surname);
            printf("Numer: %s\n", contact[i].phone_number);
            printf("-----------------------------------------\n");
        }
    }
}

int main() {
    Contact contact[10] = { {"Janek", "Propan", "11122233"},
                            {"Pawel", "Masny", "22288855"},
                            {"Kacper", "Piotrowski", "77799444"},
                            {"Kazik", "Pawlowski", "44466622"} };
    int current_contacts = 4;
    int is_on = 1;

    /*
    read_contacts(contact, current_contacts);
    del_contact(contact, &current_contacts);
    read_contacts(contact, current_contacts);
    add_contact(contact, &current_contacts);
    read_contacts(contact, current_contacts);
    search_contact(contact, current_contacts);
    */

    do {
        printf("Witaj w swojej ksiazce telefonicznej!\nOpcje:\n");
        printf("\t1. Wyswietl wszystkie kontakty\n");
        printf("\t2. Wyszukaj kontakty po nazwisku\n");
        printf("\t3. Dodaj kontakt\n");
        printf("\t4. Usun kontakt\n");
        printf("\t5. Zamknij program\n");

        int user_choice;
        scanf("%d", &user_choice);

        switch(user_choice)
        {
            case 1:
                read_contacts(contact, current_contacts);
                break;
            case 2:
                search_contact(contact, current_contacts);
                break;
            case 3:
                add_contact(contact, &current_contacts);
                break;
            case 4:
                del_contact(contact, &current_contacts);
                break;
            case 5:
                is_on = 0;
                break;
            default:
                printf("Wybrano niepoprawna opcje!");
                break;
        }

    } while (is_on == 1);

    return 0;
}
