///////////////// EXERCÍCIO DE ESTRUTURA DE DADOS /////////////////////////////
////////////////////////// LISTA DINÂMICA /////////////////////////////////////
// Profªa Liliane Machado
// Discente: Herick José de Freitas

#include <stdio.h>
#include <stdlib.h>

// Definicao das structs
struct no{
    int info;
    struct no *prox;
};

// Protótipo das funcoes
struct no* createList();

void addLastElement(struct no**);
void addFirstElement(struct no**);
void clearList(struct no**);
void deleteList(struct no**);
int isEmpty(struct no*);
void removeFirstElement(struct no**);
void removeLastElement(struct no**);
void showList(struct no*);
void sortList(struct no**);
int sizeOfList(struct no*);

int menu(struct no**);

//////////////// MAIN ////////////////////
int main(){
    struct no* l;
    l = createList();

    int n;
    do{
        n = menu(&l);
    }while(n);

    deleteList(&l);
    return 0;
}

// Menu
////////////////////////////////////////////////////////
int menu(struct no** list){
    int op;
    printf("\nMENU (Linked List):\n\t"
            "(1) Show list;\n\t"
            "(2) Add element at the end;\n\t"
            "(3) Add element at the start;\n\t"
            "(4) Remove last element;\n\t"
            "(5) Remove first element;\n\t"
            "(6) Sort list;\n\t"
            "(7) Is list empty?\n\t"
            "(8) List size\n\t"
            "(9) Clear list\n\t"
            "(0) Exit.\n"
            "Choose one option: ");
    scanf("%d", &op);

    system("cls");

    switch (op){
    case 1:
        showList(*list);
        return op;
    case 2:
        addLastElement(list);
        return op;
    case 3:
        addFirstElement(list);
        return op;
    case 4:
        removeLastElement(list);
        return op;
    case 5:
        removeFirstElement(list);
        return op;
    case 6:
        sortList(list);
        return op;
    case 7:
        if(isEmpty(*list)){
            printf("List is empty!\n\n");
        }else{
            printf("List is not empty!\n\n");
        }
        return op;
    case 8:
        printf("Size: %d\n\n", sizeOfList(*list));
        return op;
    case 9:
        clearList(list);
        printf("List cleaned!\n\n");
        return op;
    default:
        return op;
    }
}



// Implementacao das funcoes

/////////////////////////////////////////////////////////
void addLastElement(struct no** l){
    struct no* newElement = createList();
    if(!newElement){
        printf("List is full!\n\n");
        return;
    }

    printf("Enter a value (insert at the end): ");
    scanf("%d", &newElement->info);

    struct no* paux = *l;
    while(paux->prox){
        paux = paux->prox;
    }
    paux->prox = newElement;
}

////////////////////////////////////////////////////////
void addFirstElement(struct no** l){
    struct no* newElement = createList();
    if(!newElement){
        printf("List is full!\n\n");
        return;
    }
    printf("Enter a value (insert at the beggining): ");
    scanf("%d", &newElement->info);

    newElement->prox = (*l)->prox;
    (*l)->prox = newElement;
}

/////////////////////////////////////////////////////////
void clearList(struct no** l){
    struct no* paux1 = (*l)->prox;
    (*l)->prox = 0;
    struct no* paux2 = (*l)->prox->prox;
    while(1){
        free(paux1);
        paux1 = paux2;
        paux2 = paux2->prox;

        if(!paux2) break;
    }
}

/////////////////////////////////////////////////////////
struct no* createList(){
    struct no* l = (struct no*) malloc(sizeof(struct no));
    l->prox = 0;
    return l;
}

////////////////////////////////////////////////////////
void deleteList(struct no** l){
    struct no* paux1 = *l;
    struct no* paux2 = (*l)->prox;
    while(1){
        free(paux1);
        paux1 = paux2;
        paux2 = paux2->prox;

        if(!paux2) break;
    }
}

////////////////////////////////////////////////////////
int isEmpty(struct no* l){
    if(!l->prox){
        return 1;
    }
    return 0;
}

///////////////////////////////////////////////////////
void removeFirstElement(struct no** l){
    if(!isEmpty(*l)){
        struct no* paux = (*l);
        (*l) = paux->prox;
        free(paux);
    }
}

///////////////////////////////////////////////////////
void removeLastElement(struct no** l){
    struct no* paux = *l;
    while(1){
        paux = paux->prox;
        if(!paux->prox->prox){
            free(paux->prox);
            paux->prox = 0;
            break;
        }
    }
}

/////////////////////////////////////////////////////////
void showList(struct no* l){
    if(isEmpty(l)){
        printf("List is empty!\n\n");
        return;
    }
    printf("List: ");
    for(struct no* paux = l->prox; paux; paux = paux->prox){
        printf("%d%s", paux->info, paux->prox ? ", ": ".\n");
    }
}

/////////////////////////////////////////////////////////
void sortList(struct no** l){
    int tamanho = sizeOfList(*l);
    int p[tamanho];

    int i = 0;
    for(struct no* aux = *l; aux; aux = aux->prox, i++)
        p[i] = aux->info;

    for(i = 0; i < tamanho-1; i++){
        for(int j = i+1; j < tamanho; j++){
            if(p[j] < p[i]){
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    i = 0;
    for(struct no* aux = *l; aux; aux = aux->prox, i++)
        aux->info = p[i];
}

////////////////////////////////////////////
int sizeOfList(struct no* l){
    int i = 0;
    for(struct no* aux = l->prox; aux; aux = aux->prox)
        i++;
    return i;
}
