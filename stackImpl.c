/********************************************************************
 Implementação de uma pilha em C;
 Autor: Herick José
********************************************************************* */
#include <stdio.h>
#include <stdlib.h>


// structs necessárias para manipular a pilha
/**************************/
struct no{
    int data;
    struct no* next;
};
/**************************/
struct stack{
    struct no* top;
};
/**************************/

// protótipo das funções
void clean(struct stack*);                  // esvazia a pilha
void create(struct stack*);                 // inicia o topo da pilha vazio (endereço 0)
int empty(struct stack);                    // retorna 1 se estiver vazia, 0 se não
int pop(struct stack*);                     // remove o elemento que está no topo da pilha
void push(struct stack*, int);              // insere um elemento no topo da pilha
void showStack(struct stack*);               // mostra todos os elementos da pilha passada como argumento, esvaziando-a

int menu(struct stack*);

/********************************************************/
/********************************************************/
int main(){
    int n;
    struct stack s;
    create(&s);

    do{
        n = menu(&s);
    }while(n);

    clean(&s);
    system("cls");
    return 0;
}


// implementação das funções
/********************************************************/
int menu(struct stack* s){
    int n, value;
    printf("Menu:\n\t"
           "(1) show stack;\n\t"
           "(2) push;\n\t"
           "(3) pop;\n\t"
           "(4) clean;\n\t"
           "(0) exit.\n"
           "Choose an option: ");
    scanf("%d", &n);
    system("cls");

    switch(n){
        case 1:
            showStack(s);
            return n;
        case 2:
            printf("Enter a value: ");
            scanf("%d", &value);
            push(s, value);
            printf("Value %d pushed!\n", value);
            return n;
        case 3:
            if(empty(*s)){
                printf("Stack is empty!\n");
                return n;
            }else{
                printf("Value %d poped!\n", pop(s));
                return n;
            }
        case 4:
            clean(s);
            return n;
        case 0:
        default:
            return n;
    }
}

/********************************************************/
void clean(struct stack* s){
    if(empty(*s)){
        printf("Stack already empty!\n");
        return;
    }
    struct no* aux = s->top;
    while(aux){
        s->top = aux->next;
        free(aux);
        aux = s->top;
    }
    printf("Stack cleaned\n");
}

/********************************************************/
void create(struct stack* s){
    s->top = 0;
}

/********************************************************/
int empty(struct stack s){
    return !s.top;
}

/********************************************************/
int pop(struct stack* s){
    if(empty(*s)) return 0;
    struct no* aux = s->top;
    int n = aux->data;
    s->top = aux->next;
    free(aux);
    return n;
}

/********************************************************/
void push(struct stack* s, int n){
    struct no* newEl = (struct no*) malloc(sizeof(struct no));
    if(!newEl){
        printf("Wasn't possible to allocate memory!\n");
        return;
    }
    newEl->data = n;
    newEl->next = s->top;
    s->top = newEl;
}

/********************************************************/
void showStack(struct stack* s){
    if(empty(*s)){
        printf("Stack is empty!\n");
        return;
    }
    struct no* aux = s->top;
    printf("Stack: ");
    while(aux){
        printf("%d%s", aux->data, (aux-> next ? ", ":".\n"));
        pop(s);
        aux = s->top;
    }
}
