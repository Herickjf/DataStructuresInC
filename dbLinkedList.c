///////////////////////////////////////////////
///////////// DOUBLE LINKED LIST //////////////
/////////////// Profª Liliane /////////////////
//////////////// Herick José //////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* funções para corrigir:
    - removeAllOccurrences()
 */


//////////// STRUCTS /////////////////
struct no{           // list element
    struct no* prev;
    int data;
    struct no* next;
};
struct dlList{       // double linked list
    struct no* begin;
    struct no* end;
};

//////// FUNCTIONS PROTOTYPE ///////////
////////////////////////////////////////
struct dlList newList();                            // returns an empty list

void clearList(struct dlList*);                     // frees all the allocated memory
void insertAtBeginning(struct dlList*, int);        // insert a value at the beginning of the list.
void insertAtEnd(struct dlList*, int);              // insert a value at the end of the list.
void insertAtIndex(int, struct dlList*, int);       // insert a value in a given index of the list.
void insertInOrder(struct dlList*, int);            // insert a value sorted in the list (looks for a value bigger than the new one, and insert it before this bigger one).
int isEmpty(struct dlList);                         // returns 1 if list is empty, 0 if don't.
void removeAllOccurrences(struct dlList*, int);      // remove of the list all the occurances of a given value
void removeAtBeginning(struct dlList*);             // remove a value at the beginning of the list.
void RemoveAtEnd(struct dlList*);                   // remove a value at the end of the list.
void removeByIndex(int, struct dlList*);            // remove a value in a given index of the list.
void removeByValue(struct dlList*, int);            // remove of the list a given value
void showList(struct dlList);                       // show the list values in the terminal.
int sizeofList(struct dlList);                      // returns the size of a list.
void sortList(struct dlList*);                      // sorts the list values

int menu(struct dlList*);

////////////////////////////////////////
/////////////// MAIN ///////////////////
////////////////////////////////////////
int main(){
    struct dlList list = newList();
    int n;
    system("cls");
    do{
        n = menu(&list);
    }while(n);

    clearList(&list);
    return 0;
}

/////////////// MENU ///////////////////
int menu(struct dlList* list){
    int n, value, index;
    printf("******************************************************\n"
            " MENU:\n\n"
            "\t(1) show list;\n"
            "\t(2) insert value;\n"
            "\t(3) remove value;\n"
            "\t(4) sort list;\n"
            "\t(5) is empty?;\n"
            "\t(6) size of list;\n"
            "\t(7) clear list;\n"
            "\t(0) exit;\n"
            ">>> Choose one option: ");
    scanf("%d", &n);
    system("cls");

    switch(n){
        case 1: showList(*list);
                return n;
        case 2: printf("Enter a value: ");
                scanf("%d", &value);
                printf("\n>> Insert Options <<\n"
                        "\t(1) insert at the beginning;\n"
                        "\t(2) insert at the end;\n"
                        "\t(3) insert at the index;\n"
                        "\t(4) insert in order;\n"
                        "\t(5) return;\n"
                        ">>> Choose one option: ");
                scanf("%d", &n);
                system("cls");
                switch(n){
                    case 1: insertAtBeginning(list, value);
                            break;
                    case 2: insertAtEnd(list, value);
                            break;
                    case 3: printf("Enter an index: ");
                            scanf("%d", &index);
                            system("cls");
                            insertAtIndex(index, list, value);
                            break;
                    case 4: insertInOrder(list, value);
                            break;
                    case 5:
                            break;
                    default: printf("Invalid option. Try again!\n\n");
                }
                return n;
        case 3: printf("\n>> Removal Options <<\n"
                        "\t(1) remove all occurrences;\n"
                        "\t(2) remove the beginning;\n"
                        "\t(3) remove the end;\n"
                        "\t(4) remove by index;\n"
                        "\t(5) remove value;\n"
                        "\t(6) return;\n"
                        ">>> Choose one option: ");
                scanf("%d", &n);
                system("cls");
                switch(n){
                    case 1: printf("Enter a value: ");
                              scanf("%d", &value);
                              system("cls");
                              removeAllOccurrences(list, value);
                    case 2: removeAtBeginning(list);
                              break;
                    case 3: RemoveAtEnd(list);
                              break;
                    case 4: printf("Enter an index: ");
                              scanf("%d", &index);
                              system("cls");
                              removeByIndex(index, list);
                              break;
                    case 5: printf("Enter a value: ");
                              scanf("%d", &value);
                              system("cls");
                              removeByValue(list, value);
                              break;
                    case 6:
                              break;
                    default: printf("Invalid option. Try again!\n\n");
                }
                return n;
        case 4: sortList(list);
                return n;
        case 5: if(isEmpty(*list))
                    printf("List is empty!\n\n");
                else
                    printf("List is not empty!\n\n");
                return n;
        case 6: printf("Size of list is %d.\n\n", sizeofList(*list));
                return n;
        case 7: clearList(list);
                printf("List cleaned!\n\n");
                return n;
        case 0: printf("Exiting.........\n\n");
                return n;
        default: printf("This is not a valid value. Try again!\n\n");
                return n;
    }
}


///// IMPLEMENTATION OF FUNCTIONS //////
////////////////////////////////////////
struct dlList newList(){
    struct dlList l;
    l.begin = 0;
    l.end = 0;
    return l;
}



/* *************************************** */
void clearList(struct dlList* list){
    if(isEmpty(*list)){
        printf("List is empty!\n\n");
        return;
    }else if(list->begin == list->end){
        free(list->begin);
    }else{
        for(struct no* aux = list->begin->next; aux; aux = aux->next){
            free(aux->prev); // remove till the last but one
        }
        free(list->end);
    }
    *list = newList();
}

/* *************************************** */
void insertAtBeginning(struct dlList* list, int value){
    struct no* newElement = (struct no*) malloc(sizeof(struct no));
    if(newElement){
        newElement->data = value;
        newElement->prev = 0;
        newElement->next = list->begin;
        struct no* aux = list->begin;
        if(aux)
            list->begin->prev = newElement;
        else
            list->end = newElement;
        list->begin = newElement;
        printf("Value inserted at the beginning!\n\n");
    }
}

/* *************************************** */
void insertAtEnd(struct dlList* list, int value){
    struct no* newElement = (struct no*) malloc(sizeof(struct no));
    if(newElement){
        newElement->data = value;
        newElement->prev = list->end;
        newElement->next = 0;
        struct no* aux = list->end;
        if(aux)
            list->end->next = newElement;
        else
            list->begin = newElement;
        list->end = newElement;
        printf("Value inserted at the end!\n\n");
    }
}

/* *************************************** */
void insertAtIndex(int index, struct dlList* list, int value){
    if(index == 0){
        insertAtBeginning(list, value);
        return;
    }else{
        struct no* newElement = (struct no*) malloc(sizeof(struct no));
        if(newElement){
            newElement->data = value;
            int i = 0;
            for(struct no* aux = list->begin; aux; aux = aux->next, i++){
                if(i == index){
                    newElement->next = aux;
                    newElement->prev = aux->prev;
                    aux->prev->next = newElement;
                    aux->prev = newElement;
                    printf("Value inserted at index %d!\n\n", index);
                    break;
                } else if(!aux->next && i != index){
                    printf("Index out of bounds of this list!\n\n");
                }
            }
        }
    }
}

/* *************************************** */
void insertInOrder(struct dlList* list, int value){
    if(list->begin == 0){
        insertAtBeginning(list, value);
        return;
    }else{
        struct no* newElement = (struct no*) malloc(sizeof(struct no));
        if(newElement){
            newElement->data = value;
            for(struct no* aux = list->begin; aux; aux = aux->next){
                if(newElement->data < aux->data){
                    if(aux == list->begin){
                        insertAtBeginning(list, value);
                        break;
                    }
                    newElement->next = aux;
                    newElement->prev = aux->prev;
                    aux->prev->next = newElement;
                    aux->prev = newElement;
                    printf("Value inserted in order!\n\n");
                    break;
                }else if(!aux->next){
                    insertAtEnd(list, value);
                    break;
                }
            }
        }
    }
}

/* *************************************** */
int isEmpty(struct dlList list){
    if(list.begin == 0)
        return 1;
    else
        return 0;
}

/* *************************************** */
void removeAllOccurrences(struct dlList* list, int value){
    if(isEmpty(*list)){
        printf("List is empty!\n\n");
        return;
    }
    for(struct no* aux = list->begin; aux; aux = aux->next){
        if(aux->data == value){
            if(aux->prev && aux->next){
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }else if(!aux->prev && aux->next){
                aux->next->prev = 0;
                list->begin = aux->next;
            }else if(!aux->next && aux->prev){
                aux->prev->next = 0;
                list->end = aux->prev;
            }
            free(aux);
        }
    }
    printf("All occurrences of %d removed!\n\n", value);
}

/* *************************************** */
void removeAtBeginning(struct dlList* list){
    if(!isEmpty(*list)){    // if list is not empty
        struct no* aux = list->begin;
        if(aux->next){ // if list contains more than one element
            list->begin = aux->next;
            aux->next->prev = 0;
        }else{
            list->begin = 0;
            list->end = 0;
        }
        free(aux);
        printf("Beginning removed!\n\n");
    }else
        printf("List is empty!\n\n");
}

/* *************************************** */
void RemoveAtEnd(struct dlList* list){
    if(!isEmpty(*list)){    // if list is not empty
        struct no* aux = list->end;
        if(aux->prev){ // if list contains more than one element
            list->end = aux->prev;
            aux->prev->next = 0;
        }else{
            list->begin = 0;
            list->end = 0;
        }
        free(aux);
        printf("Ending removed!\n\n");
    }else
        printf("List is empty!\n\n");
}

/* *************************************** */
void removeByIndex(int index, struct dlList* list){
    if(isEmpty(*list)){
        printf("List is empty!\n\n");
        return;
    }else if(index == 0){
        removeAtBeginning(list);
        return;
    }
    int i = 0;
    for(struct no* aux = list->begin; aux; aux = aux->next, i++){
        if(i == index){
            if(aux->prev && aux->next){
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }else if(!aux->prev && aux->next){
                aux->next->prev = 0;
                list->begin = aux->next;
            }else if(!aux->next && aux->prev){
                aux->prev->next = 0;
                list->end = aux->prev;
            }
            free(aux);
            printf("Value at index %d removed!\n\n", index);
            break;
        }else if(!aux->next){
            printf("Index out of bounds of this list!\n\n");
        }
    }
}

/* *************************************** */
void removeByValue(struct dlList* list, int value){
    if(isEmpty(*list)){
        printf("List is empty!\n\n");
        return;
    }
    for(struct no* aux = list->begin; aux; aux = aux->next){
        if(aux->data == value){
            if(aux->prev && aux->next){
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }else if(!aux->prev && aux->next){
                aux->next->prev = 0;
                list->begin = aux->next;
            }else if(!aux->next && aux->prev){
                aux->prev->next = 0;
                list->end = aux->prev;
            }
            free(aux);
            printf("Value %d removed!\n\n", value);
            break;
        }else if(!aux->next){
            printf("Value not found!\n\n");
        }
    }
}

/* *************************************** */
void showList(struct dlList list){
    if(isEmpty(list)){
        printf("List is empty!\n\n");
        return;
    }else{
        printf("List: ");
        for(struct no* aux = list.begin; aux; aux = aux->next){
            printf("%d%s", aux->data, aux->next ? ", ":".\n\n");
        }
    }
}

/* *************************************** */
int sizeofList(struct dlList list){
    int i = 0;
    for(struct no* aux = list.begin; aux; aux = aux->next, i++){}
    return i;
}

/* *************************************** */
void sortList(struct dlList* list){
    if(isEmpty(*list)){
        printf("List is empty!\n\n");
        return;
    }
    for(struct no* aux = list->begin; aux; aux = aux->next){
        for(struct no* bux = aux->next; bux; bux = bux->next){
            if(bux->data < aux->data){
                int temp = aux->data;
                aux->data = bux->data;
                bux->data = temp;
            }
        }
    }
    printf("List sorted!\n\n");
}
