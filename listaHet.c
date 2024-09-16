/***********************************************************************
 * Lista de informações heterogêneos
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
//////////////// TIPOS PARA TESTE ////////////////////
typedef enum{
    Ret,
    Tri,
    Cir
}Tipo;

typedef struct{
    int b, h;
}Retangulo;

typedef struct{
    int b, h;
}Triangulo;

typedef struct{
    int r;
}Circulo;

//////////////////////////////////////////////////////

typedef struct{
    Tipo t;
    void* info;
    struct MixedList* prox;
} MixedList;

MixedList* cria_lista();

float calc_area(MixedList);
int esta_vazia(MixedList*);
void inserir_ret(MixedList**, int, int);
void inserir_tri(MixedList**, int, int);
void inserir_cir(MixedList**, int);
void limpar_lista(MixedList**);
void mostrar_area(MixedList*);
void mostrar_lista(MixedList*);
void remover_ultimo(MixedList**);

int menu(MixedList**);

//////////////////////////////////////////////////////
int main(){
    MixedList* ml = cria_lista();
    int n;

    do{
        n = menu(&ml);
    }while(n);

    limpar_lista(&ml);
    return 0;
}

int menu(MixedList** ml){
    int n, a, b;
    Tipo t;
    printf("*******************************\n"
            "LISTA DE FORMAS GEOMETRICAS\n"
            "********************************\n"
            "Menu:\n\t"
            "[1] Ver lista\n\t"
            "[2] Ver áreas\n\t"
            "[3] Inserir na Lista\n\t"
            "[4] Remover ultimo\n\t"
            "[5] Limpar lista\n\t"
            "[6] Está vazia?\n\t"
            "[0] Sair\n"
            "Escolha uma opção: ");
    scanf("%d", &n);

    system("cls");

    switch (n){
        case 1:
            mostrar_lista(*ml);
            return n;
            
        case 2:
            mostrar_area(*ml);
            return n;

        case 3:
            printf("Formas:\n\t"
                    "[1] Retangulo\n\t"
                    "[2] Triangulo\n\t"
                    "[3] Circulo\n"
                    "[0] ~ voltar\n"
                    "Escolha uma Forma: ");
            scanf("%d", &n);
            system("cls");
            switch (n){
                case 1:
                    printf("Digite as dimensoes do retangulo (b h): ");
                    scanf("%d %d", &a, &b);
                    inserir_ret(ml, a, b);
                    printf("Retangulo inserido na lista!\n");
                    return n;
                case 2:
                    printf("Digite as dimensoes do triangulo (b h): ");
                    scanf("%d %d", &a, &b);
                    inserir_tri(ml, a, b);
                    printf("Triangulo inserido na lista!\n");
                    return n;
                case 3:
                    printf("Digite o raio do circulo (r): ");
                    scanf("%d %d", &a, &b);
                    inserir_ret(ml, a, b);
                    printf("Circulo inserido na lista!\n");
                    return n;
                case 0:
                    printf("retornando...\n");
                    return n;
                default:
                    printf("Opção Inválida!\n");
                    break;
            }
            return n;

        case 4:
            remover_ultimo(ml);
            printf("Ultimo valor removido!\n");
            return n;

        case 5:
            limpar_lista(ml);
            printf("Lista esvaziada!\n");
            return n;

        case 6:
            if (esta_vazia(*ml))
                printf("Lista esta vazia!\n");
            else
                printf("Lista contem elementos!\n");
            return n;

        default:
            return n;
    }
}
//////////////////////////////////////////////////////
MixedList* cria_lista(){
    return NULL;
}

int esta_vazia(MixedList* ml){
    return !(ml->prox);
}

void inserir_ret(MixedList** ml, int b, int h){
    MixedList* novo = (MixedList*) malloc(sizeof(MixedList));
    if(!novo) return;
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    if(!r) return;
    // preenchendo o no
    novo->t = 0;  // ret (enum Tipo)
    r->b = b;
    r->h = h;
    novo->info = r;
    novo->prox = NULL;

    // inserindo no final da lista
    if(esta_vazia(*ml)){
        *ml = novo;
        return;
    }
    
    MixedList* aux = *ml;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = novo;
}
void inserir_tri(MixedList** ml, int b, int h){
    MixedList* novo = (MixedList*) malloc(sizeof(MixedList));
    if(!novo) return;
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    if(!t) return;
    // preenchendo o no
    novo->t = 1;  // tri (enum Tipo)
    t->b = b;
    t->h = h;
    novo->info = t;
    novo->prox = NULL;

    // inserindo no final da lista
    if(esta_vazia(*ml)){
        *ml = novo;
        return;
    }

    MixedList* aux = *ml;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = novo;
}
void inserir_cir(MixedList** ml, int r){
    MixedList* novo = (MixedList*) malloc(sizeof(MixedList));
    if(!novo) return;
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    if(!c) return;
    // preenchendo o no
    novo->t = 3;  // cir (enum Tipo)
    c->r = r;
    novo->info = r;
    novo->prox = NULL;

    // inserindo no final da lista
    if(esta_vazia(*ml)){
        *ml = novo;
        return;
    }

    MixedList* aux = *ml;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = novo;
}

float calc_area(MixedList no){
    Retangulo* r = NULL;
    Triangulo* t = NULL;
    Circulo* c = NULL;
    float area = 0.0f;
    switch (no.t){
        case Ret:
            r = (Retangulo*) no.info;
            area = r->b * r->h;
            return area;
        case Tri:
            r = (Triangulo*) no.info;
            area = (r->b * r->h)/2;
            return area;
        case Cir:
            c = (Circulo*) no.info;
            area = PI*pow(c->r, 2);
            return area;
    }
}

void limpar_lista(MixedList** ml){
    MixedList* aux = *ml;
    while(ml){
        *ml = aux->prox;
        free(aux->info);
        free(aux);
        aux = *ml;
    }
    ml = NULL;
}

void mostrar_area(MixedList* ml){
    if(esta_vazia(ml)){
        printf("A lista está vazia!\n\n");
        return;
    }

    int i = 0;
    MixedList* aux = ml;
    while(aux){
        printf("%d. %.2f\n", i, calc_area(*aux));
        aux = aux->prox;
        i++;
    }
}

void mostrar_lista(MixedList* ml){
    if(esta_vazia(ml)){
        printf("A lista está vazia!\n\n");
        return;
    }
    Retangulo* r = NULL;
    Triangulo* t = NULL;
    Circulo* c = NULL;

    int  i = 0;
    MixedList* aux = ml;
    while(aux){
        switch (aux->t){
            case Ret:
                r = (Retangulo*) aux->info;
                printf("%d. (Retangulo) %dx%d\n", i, r->b, r->h);
                break;
            case Tri:
                t = (Triangulo*) aux->info;
                printf("%d. (Triangulo) %dx%d\n", i, t->b, t->h);
                break;
            case Cir:
                c = (Circulo*) aux->info;
                printf("%d. (Circulo) r = %d\n", i, c->r);
                break;
        }
    }
}

void remover_ultimo(MixedList** ml){
    if(esta_vazia(*ml)){
        printf("A lista está vazia!\n\n");
        return;
    }

    MixedList* aux = *ml;
    while(aux->prox){
        aux = aux->prox;
    }
    free(aux->info);
    free(aux);
}

// S ->  0 S 1  |  1 S 0  |  SS  |  e