#include <stdio.h>
#include <stdlib.h>
//#include "lib/HcharStack.h"
#include "HcharStack.h"
#define MAX 101

int isValid(char*); // returns 1 if valid, 0 otherwise. Receives a string 

int main(){
    int op;
    do{
        printf("\n* Expression Validation * \n"
               "Menu: \n\t"
               "[1] test new expression;\n\t"
               "[0] exit.\n"
               "Enter an option: ");
        scanf("%d", &op);
        getchar();
        system("cls");
        if(op == 1){
            char expr[MAX];
            printf("Enter an expression (max 100 ch): ");
            int i = 0;
            char c;
            while((c = getchar()) != '\n' && i<MAX){
                expr[i] = c;
                i++;
            }
           expr[i] = '\0';

            system("cls");

            if(isValid(expr))
                printf("This characters sequence IS valid!\n\n");
            else   
                printf("This characters sequence IS NOT valid!\n\n");

        }else if(op != 0){
            printf("Invalid option, try again!\n\n");
        }
    }while(op);

    return 0;
}

int isValid(char *str){
    stack s;
    create(&s);

    for(int i = 0; str[i] != '\0' ; i++){
        switch(str[i]){
            case '{':
            case '[':
            case '(':
                push(&s, str[i]);
                break;

            case '}':
                if(pop(&s) != '{'){
                    clean(&s);
                    return 0;
                }
                break;
            case ']':
                if(pop(&s) != '['){
                    clean(&s);
                    return 0;
                }
                break;
            case ')':
                if(pop(&s) != '('){
                    clean(&s);
                    return 0;
                }
            default:
                break;
        }
    }

    if(!empty(s)){
        clean(&s);
        return 0;
    } 
    clean(&s);
    return 1;
}