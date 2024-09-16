#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int *dados;
    int ctrl, max;
}lista;

void addElement(lista *l, int value){
    int temp[l->max];

    for(int i = 0; i<= l->ctrl; i++)
        temp[i] = l->dados[i];

    free(l->dados);

    l->dados = (int*) malloc(sizeof(int) * l->max + 1);
    l->max+=1;

    if(!l->dados){
        printf("What a pitty, you just lost your list, fool!");
    }else{
        l->dados[l->max] = value;
        l->ctrl +=1;
    }
}

void createList(lista *l, int tamanho){
    l->dados = (int*) malloc(sizeof(int)*tamanho);
    l->max = tamanho;
    l->ctrl = -1;
}

void showList(lista l){
    for(int i=0; i<=l.ctrl; i++){
        printf("[%i] = %i\n", i, l.dados[i]);
    }
}

void deleteList(lista *l){
    free(l->dados);
    l->ctrl = -1;
}

int main(){
    lista l;
    createList(&l, 1);

    addElement(&l, 1);
    addElement(&l, 2);
    addElement(&l, 3);
    addElement(&l, 4);

    showList(l);
    deleteList(&l);

    return 0;
}
