#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

//Print node
void print_list(node_t* head) {
    node_t* current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

//Add last
void push(node_t* head, int val) {
    node_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

//Zwolnienie pamięci
void free_list(node_t* head) {
    node_t* tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

//Zadanie 1
node_t * add_first(node_t * head, int val) {
    node_t* new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = head;
    head = new_node;
    return head;
}

//Zadanie 2
node_t* remove_first(node_t* head) {
    if(head != NULL){
        node_t * new_head = head->next;
        node_t* current = head;
        free(current);
        return new_head;
    }else{
        printf("%s", "Lista jest pusta!");
    }
    return head;
}

//Zadanie 3
node_t * remove_last(node_t* head) {
    if(head==NULL){
        printf("%s", "Lista jest pusta!");
    }else if (head->next == NULL){
        head = remove_first(head);
    }else{
        node_t* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    return head;
}

//Zadanie 4
node_t* remove_by_index(node_t* head, int index) {
    node_t* current = head;
    if (index == 0) {
        head = remove_first(head);
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            if (current->next != NULL) {
                current = current->next;
            }
            else {
                printf("ERROR");
                break;
            }
        }
        node_t* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

//Zadanie 5
node_t* remove_by_value(node_t* head, int val) {
    node_t* current = head;
    if (current->val == val) {
        head = remove_first(head);
    }
    else {
        while (current->next != NULL) {
            if (current->next->val == val) {
                node_t* temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
            else {
                current = current->next;
            }
        }
    }
    return head;
}

//Zadanie 6
node_t* add_at_index(node_t* head, int val, int index) {
    node_t* new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->val = val;

    if (index == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        node_t* current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current->next != NULL) {
                current = current->next;
            } else {
                printf("ERROR: Index out of range\n");
                free(new_node);
                return head;
            }
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return head;
}

int main()
{
    node_t* head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = NULL;

    //Startowa lista:
    printf("%s", "Lista startowa: \n");
    head = add_first(head, 3);
    head = add_first(head, 6);
    head = add_first(head, 4);
    head = add_first(head, 9);
    head = add_first(head, 4);
    head = add_first(head, 11);
    print_list(head);

    printf("%s", "Usuniecie pierwszego elementu: \n");
    head = remove_first(head);
    print_list(head);

    printf("%s", "Usuniecie ostatniego: \n");
    remove_last(head);
    print_list(head);

    printf("%s", "Usuniecie indexu drugiego: \n");
    remove_by_index(head, 2);
    print_list(head);

    printf("%s", "Usuniecie wartosci 6: \n");
    remove_by_value(head, 6);
    print_list(head);

    printf("%s", "Dodanie wartosci 6 na index 2: \n");
    add_at_index(head, 6, 2);
    print_list(head);

    free_list(head);
}
