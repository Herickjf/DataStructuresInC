/* Exercícios do livro "Introdução a Estrutura de Dados"
 * pg. 214
 * Autor: Herick José de Freitas
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////////////////////////////////////

// STACK NODE
struct node{
    int info;
    struct node* next;
};
typedef struct node Node;

typedef struct{
    Node* top;
} stack;

//////// STACK FUNCS PROTS /////////

/* Deallocate the Nodes of the stack */
void clear_stack(stack*);
/* Returns a stack with a null top */
stack create_stack();
/* Fills the stack with n values with max value m*/
void fill_stack(stack*, int, int);
/* Returns 1 if the top of stack points to NULL, 0 otherwise */
int is_empty(stack);
/* Returns and removes (pops) the the top of the stack */
int pop(stack*);
/* Pushes a integer, passed as a paramether, in the stack */
void push(stack*, int);
/* Prints all the stack values, but empties it*/
void show_stack(stack*);

//////// EXERC FUNCS PROTS /////////

// 3.1.a
/* Returns the top of the stack */
int consult_stack(stack);

// 3.1.b
/* Concatenates two stacks. It puts the 2nd stack in the top of the 1st, emptying it */
void concat_stacks(stack*, stack*);

// 3.1.c
/* Returns a copy of the stack passed as a paramether */
stack copy_stack(stack*);

////////////////////////////////////

int main(){
    stack s = create_stack();

    fill_stack(&s, 10, 20);
    // test
    show_stack(&s);

    //3.1.a
    // printf("Stack top: %d\n", consult_stack(s));
    
    //3.1.b
    // stack s2 = create_stack();
    // fill_stack(&s2, 5, 10);
    // printf("Stack2 top: %d\n", consult_stack(s2));
    // concat_stacks(&s, &s2);
    // printf("Stack2: \n\t");
    // show_stack(&s2);
    // printf("Stack1: \n\t");
    // show_stack(&s);

    //3.1.c
    // stack s2 = copy_stack(&s);
    // printf("Stack1: \n\t");
    // show_stack(&s);
    // printf("Stack2: \n\t");
    // show_stack(&s2);


    clear_stack(&s);
    return 0;
}

/////////// STACK FUNCS ////////////

void clear_stack(stack* s){
    if(is_empty(*s)) return;
    while(s->top){
        pop(s);
    }
}


/******************************/
stack create_stack(){
    stack s;
    s.top = NULL;
    return s;
}

/******************************/
int is_empty(stack s){
    return (!s.top);
}

/******************************/
void fill_stack(stack* s, int n, int m){
    srand(time(0));

    for(; n; n--){
        push(s, rand() % (m+1));
    }
}

/******************************/
int pop(stack* s){
    int n;

    Node* aux = s->top;
    s->top = aux->next;
    n = aux->info;

    free(aux);

    return n;
}

/******************************/
void push(stack* s, int n){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode) return;

    newNode->info = n;
    newNode->next = s->top;
    s->top = newNode;
}

/******************************/
void show_stack(stack* s){
    if(is_empty(*s)){
        printf("Stack is empty!\n");
        return;
    }

    printf("Top -> [ ");

    for(Node* aux = s->top; aux; aux = s->top)
        printf("%d%s", pop(s), (aux->next ? ", ":" ] <- Base\n"));
    return;
}

//////////// EXERC FUNCS //////////////
int consult_stack(stack s){
    return s.top->info;
}

/******************************/
void concat_stacks(stack* s1, stack* s2){
    while(!is_empty(*s2)){
        push(s1, pop(s2));
    }
}

/******************************/
stack copy_stack(stack* s1){
    stack s2 = create_stack();
    stack aux = create_stack();

    while(!is_empty(*s1)){
        push(&aux, pop(s1));
    }

    while(!is_empty(aux)){
        int n = pop(&aux);
        push(s1, n);
        push(&s2, n);
    }

    return s2;
}
