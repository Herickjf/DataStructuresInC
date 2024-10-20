////////////////////////////////////////////////////
// Simple Queue implementation in C
// Author:  Herick José
// Date:    10/20/24
////////////////////////////////////////////////////
// imports

#include <stdio.h>
#include <stdlib.h>
#include "lib/colors.h" // change the terminal text colors


////////////////////////////////////////////////////
// structs

/* Has a data(int) and two pointers, one to the next info and other to the previus info */
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

/* Has a pointer to the begin and the end of the queue */
struct dQueue{
    Node* b;    // queue begin
    Node* e;    // queue end
};
typedef struct dQueue dQueue;


////////////////////////////////////////////////////
// funtions prototype

/* Frees all the dy namic allocated memory in the queue */
void clean_queue(dQueue**);
/* Returns a null pointered queue */
dQueue* create_queue();
/* Deallocate the queue and returns 0*/
dQueue* delete_queue(dQueue**);
/* Inserts a value in the end of the queue */
void push_back(dQueue**, int);
/* Inserts a value in the begin of the queue */
void push_front(dQueue**, int);
/* Returns 1 if queue is empty, 0 otherwise */
int queue_empty(dQueue*);
/* Returns and removes the last value of the queue */
int pop_back(dQueue**);
/* Returns and removes the first value of the queue */
int pop_front(dQueue**);
/* Prints (and removes) all the queue values  */
void show_queue(dQueue**);


////////////////////////////////////////////////////
// main function

int main(void){
    dQueue* q = create_queue();
    int choice, value;

    do{
        printf(CYAN 
              "\n************************************\n"
              "Double Queue Implementation (Herick):\n" 
              "************************************\n\n" RESET
              "Menu:\n"
              "\t[1] insert front\n"
              "\t[2] insert back\n"
              "\t[3] remove front\n"
              "\t[4] remove back\n"
              "\t[5] show\n"
              "\t[6] clean\n"
              "\t[0] exit\n"
              YELLOW "Choose one option: " RESET);
        scanf("%d", &choice);
        system("cls");

        switch(choice){
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                system("cls");
                push_front(&q, value);
                printf(GREEN "%d inserted in the Queue!\n" RESET, value);
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", &value);
                system("cls");
                push_back(&q, value);
                printf(GREEN "%d inserted in the Queue!\n" RESET, value);
                break;
            case 3:
                value = pop_front(&q);
                if(value)
                    printf(BRIGHT_RED "%d removed from the Queue!\n" RESET, value);
                break;
            case 4:
                value = pop_back(&q);
                if(value)
                    printf(BRIGHT_RED "%d removed from the Queue!\n" RESET, value);
                break;
            case 5:
                show_queue(&q);
                break;
            case 6:
                clean_queue(&q);
                printf(BRIGHT_YELLOW "Queue cleaned!\n" RESET);
                break;
            case 0:
                printf(CYAN "See you!\n" RESET);
                break;
            default:
                printf(RED "Invalid choice, try again!\n" RESET);
        }
    }while(choice);

    q = delete_queue(&q);
    return 0;
}


////////////////////////////////////////////////////
// functions implementation

void clean_queue(dQueue** q){
    // if empty returns
    if(queue_empty(*q)) return;
    
    // while not empty,
    while(!queue_empty(*q)){
        // remove each item
        pop_front(q);
    }
}

dQueue* create_queue(){
    // allocate the queue
    dQueue* q = (dQueue*) malloc(sizeof(dQueue));
    if(!q) return NULL;
    // points its the pointers to null
    q->b = NULL;
    q->e = NULL;
    return q;
}

dQueue* delete_queue(dQueue** q){
    clean_queue(q);
    free(*q);
    return NULL;
}

void push_back(dQueue** q, int value){
    if(queue_empty(*q)){
        // allocate and verify node
        Node* new = (Node*) malloc(sizeof(Node));
        if(!new) return;
        // fills the new node
        new->data = value;
        new->next = NULL;
        new->prev = NULL;
        // insert in the queue
        (*q)->b = new;
        (*q)->e = new;
    }
    else{
        // allocate and verify node
        Node* new = (Node*) malloc(sizeof(Node));
        if(!new) return;
        // fills the new node
        new->data = value;
        new->next = NULL;
        new->prev = (*q)->e;
        // insert in the queue
        (*q)->e->next = new;
        (*q)->e = new;
    }
    return;
}

void push_front(dQueue** q, int value){
    if(queue_empty(*q)){
        // allocate and verify node
        Node* new = (Node*) malloc(sizeof(Node));
        if(!new) return;
        // fills the new node
        new->data = value;
        new->next = NULL;
        new->prev = NULL;
        // insert in the queue
        (*q)->b = new;
        (*q)->e = new;
    }
    else{
        // allocate and verify node
        Node* new = (Node*) malloc(sizeof(Node));
        if(!new) return;
        // fills the new node
        new->data = value;
        new->next = (*q)->b;
        new->prev = NULL;
        // insert in the queue
        (*q)->b->prev = new;
        (*q)->b = new;
    }
    return;
}

int queue_empty(dQueue* q){
    if((q->b == q->e) && (q->b == NULL))
        return 1;
    else
        return 0;
}

int pop_back(dQueue** q){
    if(queue_empty(*q)) {
        printf(RED "Queue is empty\n" RESET);
        return 0;
    }
    // saving the value to return
    int value = (*q)->e->data;
    // saving the end and ajusting the queue
    Node* aux = (*q)->e;
    (*q)->e = (*q)->e->prev;
    //if exists another value
    if((*q)->e){
        (*q)->e->next = NULL;
    // if not
    }
    else{
        // points the begin to null also ('cause the end already does)
        (*q)->b = NULL;
    }

    // deallocating memory
    free(aux);

    return value;
}

int pop_front(dQueue** q){
    if(queue_empty(*q)) {
        printf(RED "Queue is empty\n" RESET);
        return 0;
    }
    // saving the value to return
    int value = (*q)->b->data;
    // saving the begin and ajusting the queue
    Node* aux = (*q)->b;
    (*q)->b = (*q)->b->next;
    //if exists another value
    if((*q)->b){
        (*q)->b->prev = NULL;
    // if not
    }
    else{
        // points the end to null also ('cause the begin already does)
        (*q)->e = NULL;
    }

    // deallocating memory
    free(aux);

    return value;
}

void show_queue(dQueue** q){
    if(queue_empty(*q)){
        printf(RED "Queue is empty!\n" RESET);
        return;
    }

    printf("Queue: ");
    while(!queue_empty(*q)){
        if((*q)->b->next)
            printf("%d -> ", pop_front(q));
        else
            printf("%d\n", pop_front(q));
    }
    return;
}