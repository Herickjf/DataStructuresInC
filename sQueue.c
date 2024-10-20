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
struct sQueue{
    Node* b;    // queue begin
    Node* e;    // queue end
};
typedef struct sQueue sQueue;


////////////////////////////////////////////////////
// funtions prototype

/* Frees all the dy namic allocated memory in the queue */
void clean_queue(sQueue**);
/* Returns a null pointered queue */
sQueue* create_queue();
/* Deallocate the queue and returns 0*/
sQueue* delete_queue(sQueue**);
/* Inserts a value in the end of the queue */
void insert_in_queue(sQueue**, int);
/* Returns 1 if queue is empty, 0 otherwise */
int queue_empty(sQueue*);
/* Returns and removes the first value of the queue */
int remove_from_queue(sQueue**);
/* Prints (and removes) all the queue values  */
void show_queue(sQueue**);


////////////////////////////////////////////////////
// main function

int main(void){
    sQueue* q = create_queue();
    int choice, value;

    do{
        printf(CYAN 
              "\n************************************\n"
              "Simple Queue Implementation (Herick):\n" 
              "************************************\n\n" RESET
              "Menu:\n"
              "\t[1] insert\n"
              "\t[2] remove\n"
              "\t[3] show\n"
              "\t[4] clean\n"
              "\t[0] exit\n"
              YELLOW "Choose one option: " RESET);
        scanf("%d", &choice);
        system("cls");

        switch(choice){
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                system("cls");
                insert_in_queue(&q, value);
                printf(GREEN "%d inserted in the Queue!\n\n" RESET, value);
                break;
            case 2:
                value = remove_from_queue(&q);
                if(value)
                    printf(BRIGHT_RED "%d removed from the Queue!\n\n" RESET, value);
                break;
            case 3:
                show_queue(&q);
                break;
            case 4:
                clean_queue(&q);
                printf(BRIGHT_YELLOW "Queue cleaned!\n\n" RESET);
                break;
            case 0:
                printf(CYAN "See you!\n\n" RESET);
                break;
            default:
                printf(RED "Invalid choice, try again!\n\n" RESET);
        }
    }while(choice);

    q = delete_queue(&q);
    return 0;
}


////////////////////////////////////////////////////
// functions implementation

void clean_queue(sQueue** q){
    // if empty returns
    if(queue_empty(*q)) return;
    
    // while not empty,
    while(!queue_empty(*q)){
        // remove each item
        remove_from_queue(q);
    }
}

sQueue* create_queue(){
    // allocate the queue
    sQueue* q = (sQueue*) malloc(sizeof(sQueue));
    if(!q) return NULL;
    // points its the pointers to null
    q->b = NULL;
    q->e = NULL;
    return q;
}

sQueue* delete_queue(sQueue** q){
    clean_queue(q);
    free(*q);
    return NULL;
}

void insert_in_queue(sQueue** q, int value){
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

    }else{
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

int queue_empty(sQueue* q){
    if((q->b == q->e) && (q->b == NULL))
        return 1;
    else
        return 0;
}

int remove_from_queue(sQueue** q){
    if(queue_empty(*q)) {
        printf(YELLOW "Queue is empty\n\n" RESET);
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
    }else{
        // points the end to null also ('cause the begin already does)
        (*q)->e = NULL;
    }

    // deallocating memory
    free(aux);

    return value;
}

void show_queue(sQueue** q){
    if(queue_empty(*q)){
        printf("Queue is empty!\n\n");
        return;
    }

    printf("Queue: ");
    while(!queue_empty(*q)){
        if((*q)->b->next)
            printf("%d -> ", remove_from_queue(q));
        else
            printf("%d\n\n", remove_from_queue(q));
    }
    return;
}