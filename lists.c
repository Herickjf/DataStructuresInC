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
void addListItem(List *, int);
void createList(List *);
void clearList(List *);
char isListFull(List);
char isListEmpty(List);
void removeListItem(List *);
void showList(List);
void sortList(List *);


// Main
int main(){
    List l;

    createList(&l);
    addListItem(&l, 0);
    addListItem(&l, 10);
    addListItem(&l, 1);
    sortList(&l);
    showList(l);
    clearList(&l);

    addListItem(&l, 200);
    addListItem(&l, 1);
    addListItem(&l, 15);
    removeListItem(&l);
    sortList(&l);
    showList(l);

    return 0;
}


// Implementação das Funções
void addListItem(List *l, int n){
    if(isListFull(*l) == '0'){
        //l->p[l->ctrl+1] = (int *) malloc(sizeof(int));
        l->p[l->ctrl+1] = n;
        l->ctrl +=1;
    }else{
        printf("\nItem was'nt added to the List, because the List is full!\n");
    }
}

void createList(List *l){
    l->ctrl = -1;
}

void clearList(List *l){
    createList(l);
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

void removeListItem(List *l){
    l->ctrl -=1;
}

void showList(List l){
    if(isListEmpty(l) == '0'){
        printf("List: ");
        for(int i = 0; i <= l.ctrl; i++)
            printf("%d%c ", l.p[i], i == l.ctrl ? '.':',');
    }else{
        printf("\nIs'nt possible to show the List, because it is empty!\n");
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
    }
}

