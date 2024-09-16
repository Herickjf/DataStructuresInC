#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y;
}Ponto;

struct no{
    Ponto* info;
    struct no* prox;
};

//funções c/ uso de callback
// int (*cb)(void*, void*);
int compara(void*, void*);
int mostra(void*, void*);
int percorre(struct no**, int (*cb)(void*, void*), void*);

//funcoes de lista
void inserir(struct no**, int, int);
void limpar(struct no**);

int main(){
    int x, y;
    struct no* lista = NULL;
    //inserindo o ponto (10, 20) na lista
    inserir(&lista, 10, 20);
    //inserindo o ponto (2,4) na lista
    inserir(&lista, 2, 4);
    //inserindo o ponto (3,-1) na lista
    inserir(&lista, 3, -1);
    //inserindo o ponto (1,1) na lista
    inserir(&lista, 1, 1);
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if(!p) return 0;
    printf("Procure um ponto da lista! Insira um ponto (x,y): ");
    scanf("%d,%d", &x, &y);
    p->x = x;
    p->y = y;

    if(percorre(&lista, compara, p))
        printf("Ponto (%d, %d) encontrado na lista!\n\n", p->x, p->y);
    else
        printf("Ponto (%d, %d) nao encontrado na lista!\n\n", p->x, p->y);

    free(p);

    //usando percorre para mostrar a lista
    printf("Os pontos da lista eram:\n[");
    percorre(&lista, mostra, NULL);
    printf("]\n");

    limpar(&lista);
    return 0;
}

int compara(void* ponto1, void* ponto2){
    Ponto* p1 = (Ponto*) ponto1;
    Ponto* p2 = (Ponto*) ponto2;
    if(p1&&p2 && p1->x == p2 ->x && p1->y == p2->y)
        return 1;
    return 0;
}

int mostra(void* ponto, void* unused){
    (void) unused;
    Ponto* p = (Ponto*) ponto;
    printf(" (%d, %d) ", p->x, p->y);
    return 0;
}

int percorre(struct no** lista, int (*cb)(void*, void*), void* valor2){
    struct no* aux = *lista;
    for(; aux; aux = aux->prox){
        int ret = (*cb)(aux->info, valor2);
        if(ret) return ret;
    }
    return 0;
}

void inserir(struct no** lista, int x, int y){
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    if(!novo) return;
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    if(!p) return;
    //preenche o ponto
    p->x = x;
    p->y = y;
    //insere no nó
    novo->info = p;
    novo->prox = *lista;
    *lista = novo; 
}

void limpar(struct no** lista){
    struct no* aux = *lista;
    while(aux){
        *lista = aux->prox;
        free(aux->info);
        free(aux);
        aux = *lista;
    }
}