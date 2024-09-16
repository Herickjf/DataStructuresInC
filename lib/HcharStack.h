#ifndef HCHARSTACK_H
#define HCHARSTACK_H
/********************************************************************
* Stack implementation in C;
* Autor: Herick Jose
********************************************************************* */
/********************************************************/
#include <stdio.h>
#include <stdlib.h>

// necessary structs to implement stack

/***************************
 * node is a piece of stack, each piece of stack is a node
 * *************************/
struct node{
    char data;
    struct node* next;
};
/***************************
 * stack only contains the top of the stack, which one is also a node
 * each node will make the connection with the next one, till the last, in which the next = 0
 * *************************/
typedef struct{
    struct node* top;
}stack;

////////////////////////////////////////
////////////// FUNCTIONS ///////////////
////////////////////////////////////////

/***************************
 * empty(stack) returns 1 if the stack's empty, 0 otherwise
 * *************************/
int empty(stack s){
    return !s.top;
}

/***************************
 * clean(stack) will deallocate all the memory allocated in the stack
 * and make the stack->top equal to 0
 * *************************/
void clean(stack* s){
    if(empty(*s)){
        //printf("Stack already empty!\n");
        return;
    }
    struct node* aux = s->top;
    while(aux){
        s->top = aux->next;
        free(aux);
        aux = s->top;
    }
    //printf("Stack cleaned\n");
}

/***************************
 * create(stack) will make the stack->top equal to 0, what means it's empty now
 * *************************/
void create(stack* s){
    s->top = 0;
}


/***************************
 * pop(stack) removes and returns the top of the stack
 * *************************/
char pop(stack* s){
    if(empty(*s)) return '\0';
    struct node* aux = s->top;
    char c = aux->data;
    s->top = aux->next;
    free(aux);
    return c;
}

/***************************
 * push(stack, value) puts the value on the top of the stack
 * *************************/
void push(stack* s, char c){
    struct node* newEl = (struct node*) malloc(sizeof(struct node));
    if(!newEl){
        printf("Wasn't possible to allocate memory!\n");
        return;
    }
    newEl->data = c;
    newEl->next = s->top;
    s->top = newEl;
}

/***************************
 * showStack(stack) prints all the values of the stack
 * ALERT: by showing the values of a stack, you're automatically removing all of them
 * *************************/
void showStack(stack* s){
    if(empty(*s)){
        printf("Stack is empty!\n");
        return;
    }
    struct node* aux = s->top;
    printf("Stack: ");
    while(aux){
        printf("%c%s", aux->data, (aux-> next ? ", ":".\n"));
        pop(s);
        aux = s->top;
    }
}

#endif