//////////////////////////////////////////////
// Fila implementada em vetor
// Autor: Herick José de Freitas
//////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//////// definição da lista circular //////////
typedef struct{
    int dados[MAX];
    int i,f;
}ListaC;

void criar(ListaC*);        // inicializa os marcadores de início e fim com valor -1
int consultar(ListaC);      // retorna o valor que está no início
int esta_vazia(ListaC);     // retorna 1 se vazia, 0 se não vazia
int esta_cheia(ListaC);     // retorna 1 se cheia, 0 se não cheia
void inserir(ListaC*, int); // insere um valor no final
void remover(ListaC*);      // remove um valor do início         

int menu(ListaC*);

int main(){
    int n;
    ListaC l;
    criar(&l);

    do{
        n = menu(&l);
    }while(n);

    return 0;
}

int menu(ListaC* l){
    int op, valor;
    printf("\n----------------------------\n"
           "--> Implementacao de Fila\n"
           "----------------------------\n"
           "Menu: \n\t"
           "[1] inserir na fila;\n\t"
           "[2] remover da fila;\n\t"
           "[3] consultar a fila;\n\t"
           "[4] esvaziar a fila;\n\t"
           "[5] esta vazia?\n\t"
           "[6] esta cheia?\n\t"
           "[0] sair.\n"
           "Escolha uma opcao: ");
    scanf("%d", &op);
    system("cls");
    switch(op){
        case 1:
            if(esta_vazia(*l)){
                printf("A fila esta cheia!\n");
                return op;
            }
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            system("cls");
            inserir(l, valor);
            return op;
        case 2:
            remover(l);
            return op;
        case 3:
            if(esta_vazia(*l))
                printf("A fila esta vazia!\n");
            else
                printf("O valor que espera na fila eh %d !\n", consultar(*l));
            return op;
        case 4:
            criar(l);
            printf("Fila esvaziada!\n");
            return op;
        case 5:
            if(esta_vazia(*l))
                printf("A fila esta vazia!\n");
            else
                printf("A fila nao esta vazia!\n");
            return op;
        case 6:
            if(esta_cheia(*l))
                printf("A fila esta cheia!\n");
            else
                printf("A fila nao esta cheia!\n");
            return op;
        case 0:
        default:
            return op;
    }
}

void criar(ListaC* l){
    l->f = -1;
    l->i = -1;
}

int consultar(ListaC l){
    if(!esta_vazia(l))
        return l.dados[l.i];
    return -1;
}

int esta_vazia(ListaC l){
    if(l.f == l.i && l.i == -1)
        return 1;
    return 0;
}

int esta_cheia(ListaC l){
    if((l.i == 0 && l.f == MAX-1) || (l.f == l.i-1))
        return 1;
    return 0;
}

void inserir(ListaC* l, int valor){
    if(esta_cheia(*l)){
        printf("A fila esta cheia!\n");
        return;
    }else if(esta_vazia(*l)){
        l->dados[0] = valor;
        l->i = l->f = 0;
    }else{
        l->dados[(l->f+1)%MAX] = valor;
        l->f = (l->f+1)%MAX;
    }
    printf("Valor %d inserido na fila!\n", valor);
}

void remover(ListaC* l){
    if(esta_vazia(*l)){
        printf("A fila está vazia!\n");
        return;
    }
    if(l->i == l->f){
        criar(l);
        return;
    }
    l->i = (l->i+1)%MAX;
}      