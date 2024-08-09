// Manipulação de Listas em C : Introdução às Estruturas de Dados

#include <stdio.h>
#include <stdlib.h>


// Definições
#define MAX 10


// Estruturas
typedef struct{
    int p[MAX];
    int ctrl;
} List;


// Protótipo das Funções
void addListItem(List *);
void createList(List *);
void clearList(List *);
char isListFull(List);
char isListEmpty(List);
void removeListItem(List *);
void showList(List);
void sortList(List *);

int menu(List *);


// Main
int main(){
    List l;
    createList(&l);
    int n = 1;

    while(n){
        n = menu(&l);
    }
    return 0;
}


// Implementação das Funções
void addListItem(List *l){
    if(isListFull(*l) == '0'){
        int n;
        //l->p[l->ctrl+1] = (int *) malloc(sizeof(int));
        printf("Add the item: ");
        scanf("%d", &n);
        l->p[l->ctrl+1] = n;
        l->ctrl +=1;
        printf("Item added!\n\n");
    }else{
        printf("\nItem was'nt added, the List is full!\n\n");
    }
}

void createList(List *l){
    l->ctrl = -1;
    printf("List Created!\n\n");
}

void clearList(List *l){
    l->ctrl = -1;
    printf("List Cleaned!\n\n");
}

char isListFull(List l){
    if(l.ctrl < MAX){
        return '0';
    }else{
        return '1';
    }
}

char isListEmpty(List l){
    if(l.ctrl == -1){
        return '1';
    }else{
        return '0';
    }
}

int menu(List *l){
    int n;
    printf("Menu:\n\t"
           "(1)Create List;\n\t"
           "(2)Add Item to List;\n\t"
           "(3)Remove Item from List;\n\t"
           "(4)Get List Size;\n\t"
           "(5)See List;\n\t"
           "(6)Sort List;\n\t"
           "(7)Clear List;\n\t"
           "(0)Exit.\n"
           "Choose an option: ");

    scanf("%d", &n);

    system("cls");

    switch(n){
        case 0: return 0;
        case 1: createList(l);
                return 1;
        case 2: addListItem(l);
                return 1;
        case 3: removeListItem(l);
                return 1;
        case 4: printf("Size of List: %d\n\n", l->ctrl + 1);
                return 1;
        case 5: showList(*l);
                return 1;
        case 6: sortList(l);
                return 1;
        case 7: clearList(l);
                return 1;
        default:printf("This is'nt a valid option. Try again!\n\n");
                return 1;

    }
}

void removeListItem(List *l){
    l->ctrl -=1;
    printf("Last list item removed!\n\n");
}

void showList(List l){
    if(isListEmpty(l) == '0'){
        printf("List: ");
        for(int i = 0; i <= l.ctrl; i++)
            printf("%d%c ", l.p[i], i == l.ctrl ? '.':',');
        printf("\n\n");
    }else{
        printf("List is empty!\n\n");
    }
}

void sortList(List *l){
    if(isListEmpty(*l) == '0'){
        for(int i = 0; i <= l->ctrl; i++){
            for(int j = 0; j <= l->ctrl; j++){
                if(l->p[i] < l->p[j]){
                    int aux = l->p[i];
                    l->p[i] = l->p[j];
                    l->p[j] = aux;
                }
            }
        }
        printf("List sorted!\n\n");
    }
}
