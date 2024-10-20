////////////////////////////////////////////////////
// Mixed Stack implementation in C
// Author:  Herick José
// Date:    10/20/24
////////////////////////////////////////////////////
// imports
#include <stdio.h>
#include <stdlib.h>
#include "lib/colors.h" // change the terminal text colors


////////////////////////////////////////////////////
// structs
struct node{
    char type;
    void* data;
    struct node* next;
};
typedef struct node Node;

struct stack{
    Node* top;
};
typedef struct stack Stack;


////////////////////////////////////////////////////
// functions prototype
/* Deallocate all the memory previously allocated */
void clean_stack(Stack**);
/* Returns a null pointered stack */
Stack* create_stack();
/* Deletes the stack and returns a null pointer */
Stack* delete_stack(Stack**);
/* Returns 1 if stack is empty, 0 otherwise */
int isEmpty(Stack*);
/* Prints and removes the top of the stack */
void pop(Stack**);
/* Receives a stack, a info (allocated previouslly) and a char type and inserts it properly in the top of the stack */
void push(Stack**, void*, char);
/* Prints and removes all of the values of the stack */
void show_stack(Stack**);

////////////////////////////////////////////////////
// main function
int main(void){
    Stack* s = create_stack();
    int choice, iValue; 
    char type, cValue;
    float fValue;
    int* iInfo;
    float* fInfo;
    char* cInfo;

    do{
        printf(CYAN 
              "\n************************************\n"
              "Mixed Stack Implementation (Herick):\n" 
              "************************************\n\n" RESET
              "Menu:\n"
              "\t[1] insert char\n"
              "\t[2] insert float\n"
              "\t[3] insert int\n"
              "\t[4] remove value\n"
              "\t[5] show\n"
              "\t[6] clean\n"
              "\t[0] exit\n"
              YELLOW "Choose one option: " RESET);
        scanf("%d", &choice);
        system("cls");

        switch(choice){
            case 1:
                printf(YELLOW "Enter a char: " RESET);
                scanf(" %c", &cValue);
                system("cls");
                cInfo = (char*)malloc(sizeof(char));
                if(!cInfo){
                    printf(RED "No free memory!\n" RESET);
                    return 0;
                }
                *cInfo = cValue;
                push(&s, cInfo, 'c');
                printf(GREEN "'%c' inserted in the List!\n" RESET, cValue);
                break;
            case 2:
                printf(YELLOW "Enter a float: " RESET);
                scanf("%f", &fValue);
                system("cls");
                fInfo = (float*)malloc(sizeof(float));
                if(!fInfo){
                    printf(RED "No free memory!\n" RESET);
                    return 0;
                }
                *fInfo = fValue;
                push(&s, fInfo, 'f');
                printf(GREEN "%.2f inserted in the List!\n" RESET, fValue);
                break;
            case 3:
                printf(YELLOW "Enter a integer: " RESET);
                scanf("%i", &iValue);
                system("cls");
                iInfo = (int*)malloc(sizeof(int));
                if(!iInfo){
                    printf(RED "No free memory!\n" RESET);
                    return 0;
                }
                *iInfo = iValue;
                push(&s, iInfo, 'i');
                printf(GREEN "%d inserted in the List!\n" RESET, iValue);
                break;
            case 4:
                pop(&s);
                break;
            case 5:
                show_stack(&s);
                break;
            case 6:
                clean_stack(&s);
                printf(BRIGHT_YELLOW "Stack cleaned!\n" RESET);
                break;
            case 0:
                printf(CYAN "See you!\n" RESET);
                break;
            default:
                printf(RED "Invalid choice, try again!\n" RESET);
        }
    }while(choice);

    s = delete_stack(&s);
    return 0;
}


////////////////////////////////////////////////////
// functions implementation

void clean_stack(Stack** s){
    if(isEmpty(*s)) return;

    Node* aux = (*s)->top;
    while(aux){
        Node* bux = aux;
        aux = aux->next;
        free(bux->data);
        free(bux);
    }

    (*s)->top = NULL;
}

Stack* create_stack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if(!s) return NULL;

    s->top = NULL;
    return s;
}

Stack* delete_stack(Stack** s){
    if(!isEmpty(*s))
        clean_stack(s);

    free(*s);
    *s = NULL;
    return NULL;
}

int isEmpty(Stack* s){
    return !s->top;
}

void pop(Stack** s){
    if(isEmpty(*s)){
        printf("Stack is empty!\n");
        return;
    }
    Node* aux = (*s)->top;
    switch(aux->type){
        case 'c':
            printf(BLUE "(" CYAN "char" BLUE") '%c'" RESET, *((char*) aux->data));
            break;
        case 'f':
            printf(BLUE "(" CYAN "float" BLUE") %.3f" RESET, *((float*) aux->data));
            break;
        case 'i':
            printf(BLUE "(" CYAN "int" BLUE") %d" RESET, *((int*) aux->data));
            break;
        default:
            return;
    }

    (*s)->top = aux->next;
    free(aux);

    return;
}

void push(Stack** s, void* info, char type){
    Node* new = (Node*)malloc(sizeof(Node));
    if(!new) return;
    new->type = type;
    new->data = info;
    new->next = (*s)->top;
    (*s)->top = new;
}

void show_stack(Stack** s){
    printf("Stack -> [ \n\t");
    for(Node* aux = (*s)->top; aux; aux = (*s)->top){
        pop(s);
        if(aux->next)
            printf(" ,\n\t");
    }
    printf(" ].\n");
}