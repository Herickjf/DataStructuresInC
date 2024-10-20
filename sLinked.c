////////////////////////////////////////////////////
// Simple Linked Ordered List implementation in C
// Author:  Herick José
// Date:    10/20/24
////////////////////////////////////////////////////
// imports
#include <stdio.h>
#include <stdlib.h>
#include "lib/colors.h" // change the terminal text colors


////////////////////////////////////////////////////
// structs
/* Has a data(int) and a pointers to the next info  */
struct node{
    int data;
    struct node* next;
};
typedef struct node Node;


////////////////////////////////////////////////////
// functions prototype

/* Cleans the list and returns a NULL pointer */
Node* cleanList(Node**);
/* Receives two lists and returns their concatenation */
Node* concat(Node*, Node*);
/* Returns 1 if the list contains the value, 0 otherwise */
int contains(Node*, int);
/* Returns a NULL pointer */
Node* createList();
/* Returns 1 if list is empty, 0 otherwise */
int empty(Node*);
/* Insert a value in the ordered list */
void insert(Node**, int);
/* Removes a value passed as a paramether */
void removeVal(Node**, int);
/* Removes all occurrences of the value passed as a parameter */
void removeAll(Node**, int);
/* Show the list */
void show_list(Node*);


////////////////////////////////////////////////////
// main function

int main(void){
    Node* l = createList();
    int choice, value;

    do{
        printf(CYAN 
              "\n************************************\n"
              "Ordered List Implementation (Herick):\n" 
              "************************************\n\n" RESET
              "Menu:\n"
              "\t[1] insert\n"
              "\t[2] remove value\n"
              "\t[3] remove all occurrences\n"
              "\t[4] show\n"
              "\t[5] clean\n"
              "\t[0] exit\n"
              YELLOW "Choose one option: " RESET);
        scanf("%d", &choice);
        system("cls");

        switch(choice){
            case 1:
                printf(YELLOW "Enter a value: " RESET);
                scanf("%d", &value);
                system("cls");
                insert(&l, value);
                printf(GREEN "%d inserted in the List!\n" RESET, value);
                break;
            case 2:
                printf(YELLOW "Enter a value: " RESET);
                scanf("%d", &value);
                system("cls");
                removeVal(&l, value);
                printf(GREEN "%d removed from the List!\n" RESET, value);
                break;
            case 3:
                printf(YELLOW "Enter a value: " RESET);
                scanf("%d", &value);
                system("cls");
                removeVal(&l, value);
                removeAll(&l, value);
                printf(BRIGHT_RED "All occurrences of %d removed from the List!\n" RESET, value);
                break;
            case 4:
                show_list(l);
                break;
            case 5:
                l = cleanList(&l);
                printf(BRIGHT_YELLOW "List cleaned!\n" RESET);
                break;
            case 0:
                printf(CYAN "See you!\n" RESET);
                break;
            default:
                printf(RED "Invalid choice, try again!\n" RESET);
        }
    }while(choice);

    l = cleanList(&l);
    return 0;
}


////////////////////////////////////////////////////
// functions implementation

Node* cleanList(Node** l){
    if(empty(*l)) return NULL;

    Node* aux = *l;
    while(aux->next){
        Node* bux = aux->next;
        free(aux);
        aux = bux;
    }
    free(aux);

    *l = NULL;
    return NULL;
}

Node* concat(Node* l1, Node* l2){
    if(empty(l1) && empty(l2)) return NULL;
    Node* l3 = createList();

    // its an ordered list, so i can insert the values and the funtion insert will order it
    Node* aux = l1;
    while(aux){
        insert(&l3, aux->data);
        aux = aux->next;
    }
    aux = l2;
    while(aux){
        insert(&l3, aux->data);
        aux = aux->next;
    }

    return l3;
}

int contains(Node* l, int value){
    if(empty(l)) return 0;

    Node* aux = l;
    while(aux){
        if(aux->data == value)
            return 1;

        aux = aux->next;
    }
    return 0;
}

Node* createList(){
    return NULL;
}

int empty(Node* l){
    return !l;
}


void insert(Node** l, int value){
    // creating node
    Node* new = (Node*) malloc(sizeof(Node));
    if(!new) return;
    // fills the Node
    new->data = value;
    new->next = NULL;

    if(empty(*l)){
        // inserts it in the list
        *l = new;
        return;
    }

    // walking the list
    Node* aux = *l;
    // if its smaller than the first value
    if(value < aux->data){
        new->next = aux;
        *l = new;
        return;
    }

    // if it has to insert in the middle of the list
    while(aux->next){
        if(value <= aux->next->data){
            new->next = aux->next;
            aux->next = new;
            return;
        }
        aux = aux->next;
    }

    // if it has to insert at the end of the list
    aux->next = new;
    // printf("Problem not here");
    return;

}

void removeVal(Node** l, int value){
    if(empty(*l)) {
        printf("List is empty!\n");
        return;
    }

    Node* aux = *l;
    if(aux->data == value){
        *l = aux->next;
        free(aux);
        return;
    }

    while(aux->next){
        if(aux->next->data == value){
            Node* bux = aux->next;
            aux->next = bux->next;
            free(bux);
            return;
        }

        if(!aux->next->next){
            if(aux->next->data == value){
                free(aux->next);
                aux->next = NULL;
                return;
            }
        }
        aux = aux->next;
    }
}

void removeAll(Node** l, int value){
    if(empty(*l)) {
        printf("List is empty!\n");
        return;
    }

    while(contains(*l, value)){
        removeVal(l, value);
    }

    return;
}

void show_list(Node* l){
    printf("List: [ ");
    for(Node* aux = l; aux; aux = aux->next)
        printf(BLUE "%d" RESET "%s", aux->data, aux->next? ", ":"");
    printf(" ].\n");
    
    return;
}