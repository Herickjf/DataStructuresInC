/* Exercícios do livro "Introdução a Estrutura de Dados"
 * pg. 214
 * Autor: Herick José de Freitas
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////////////////////////////////////

// nó da lista
struct node{
    int info;
    struct node* next;
};
typedef struct node Node;

///////// FUNÇÕES DE LISTA ////////////
// protótipo das funções

/*Retorna um ponteiro nulo*/
Node* create_list();
/*Preenche a lista com n valores aleatorios de tamanho maximo m*/
void fill_list(Node**, int, int);
/*Retorna 1 se a lista estiver vazia, 0 caso contrário*/
int is_empty(Node*);
/*Insere um inteiro -- passado como parâmetro -- no fim da lista */
void push_back(Node**, int);
/*Insere um inteiro -- passado como parâmetro -- no início da lista */
void push_front(Node**, int);
/*Remove o último elemento da lista */
void pop_back(Node**);
/*Remove o primeiro elemento da lista */
void pop_front(Node**);
/*Desaloca todos os nós e faz a lista apontar para nulo */
void reset_list(Node**);
/*Printa a lista no terminal*/
void show_list(Node*);

/////// FUNÇÕES DO EXERCÍCIO ///////

/* Questão 2.1
 * Função que retorne o comprimento de uma lista */
int sizeof_list(Node*);

/* Questão 2.2
 * Função que retorne o número de valores maiores que um dado n */
int biggests(Node*, int);

/* Questão 2.3
 * Função que retorne um ponteiro para o último elemento de uma lista */
Node* last_elem(Node*);

/* Questão 2.4
 * Função que recebe duas listas e retorna a concatenação delas */
Node* concat_lists(Node*, Node*);

/* Questão 2.5.1
 * Função que retire um valor n da lista */
void remove_val(Node**, int);
/* Questão 2.5.2
 * Função que retire todas as ocorrências de um valor na lista */
void remove_all_vals(Node**, int);

/* Questão 2.6
 * Função que separa a lista a partir de um valor e retorna a segunda sublista, 
 * enquanto a primeira acaba no valor informado */
Node* separetes_list(Node**, int);

/* Questao 2.7
 * Função que devolve uma lista com a intercalação de outras duas listas passadas como parametro */
Node* merge_lists(Node*, Node*);

/* Questão 2.8
 * Função que retorna uma lista passada como parametro invertida */
Node* invert_list(Node*);

/* Questão 2.9
 * Função que retorna 1 se as listas passadas como parametro são iguais, 0 caso contrário */
int equals(Node*, Node*);

/* Questão 2.10 
 * Função que retorna a copia de uma lista passada como parametro */
Node* copy_list(Node*);

////////////////////////////////////
int main(){
    Node* list = create_list();

    fill_list(&list, 10, 100);
    // pop_front(&list);
    show_list(list);

    // 2.1
    // printf("\nTamanho da lista: %d\n", sizeof_list(list));

    // 2.2
    // printf("\nNumero de elementos maiores que %d : %d\n", 50, biggests(list, 50));

    // 2.3
    // Node* last = last_elem(list);
    // printf("\nUltimo elemento da lista: %d\n", last->info);

    // 2.4
    // Node* l2 = create_list();
    // fill_list(&l2, 5, 20);
    // printf("Lista 2: ");
    // show_list(l2);
    // Node* l3 = concat_lists(list, l2);
    // printf("Lista 3: ");
    // show_list(l3);
    // reset_list(&l2);
    // reset_list(&l3);

    // 2.5.1
    // int n;
    // printf("Remove value: ");
    // scanf("%d", &n);
    // remove_val(&list, n); 
    // show_list(list);

    // 2.5.2
    // int n;
    // printf("Insert value: "); // duplicar um valor
    // scanf("%d", &n);
    // push_back(&list, n);
    // show_list(list);
    // printf("Remove value: ");
    // scanf("%d", &n);
    // remove_all_vals(&list, n); 
    // show_list(list);

    // 2.6
    // int n;
    // printf("Apart list at: ");
    // scanf("%d", &n);
    // Node* l2 = separetes_list(&list, n);
    // printf("Lista 1: ");
    // show_list(list);
    // printf("Lista 2: ");
    // show_list(l2);

    // 2.7
    // Node* l2 = create_list();
    // fill_list(&l2, 5, 20);
    // printf("Lista 2: ");
    // show_list(l2);
    // Node* l3 = merge_lists(list, l2);
    // printf("Lista 3: ");
    // show_list(l3);
    // reset_list(&l2);
    // reset_list(&l3);

    // 2.8
    // Node* l2 = invert_list(list);
    // printf("Lista 2: ");
    // show_list(l2);

    // 2.9
    // Node* l2 = create_list();
    // fill_list(&l2, 5, 20);
    // // l2 = list;
    // printf("Lista 2: ");
    // show_list(l2);
    // if(equals(list, l2)){
    //     printf("As listas sao iguais!\n");
    // }else{
    //     printf("As listas sao diferentes!\n");
    // }

    // 2.10
    Node* l2 = copy_list(list);
    printf("Lista 2: ");
    show_list(l2);


    reset_list(&list);
    return 0;
}

//////// IMPLEMENTAÇÃO DAS FUNCÕES DE LISTA ///////////////

Node* create_list(){
    return NULL;
}

/**************************************/
void fill_list(Node** l, int n, int m){
    srand(time(0));
    for(; n > 0; n--){
        push_front(l, (rand() % m+1));
    }
}

/**************************************/
int is_empty(Node* l){
    return (!l);
}

/**************************************/
void push_back(Node** l, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode) return;
    newNode->info = value;
    newNode->next = NULL;

    if(!*l){
        *l = newNode;
        return;
    }

    Node* aux = *l;
    while(aux->next){
        aux = aux->next;
    }
    aux->next = newNode;
}

/**************************************/
void push_front(Node** l, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode) return;

    newNode->info = value;
    newNode->next = *l;
    *l = newNode;
}

/**************************************/
void pop_front(Node** l){
    if(is_empty(*l)) return;

    Node* aux = *l;
    *l = aux->next;
    free(aux);

}

/**************************************/
void pop_back(Node** l){
    Node* aux = *l;

    // caso esteja vazia
    if(is_empty(*l)) return;

    // caso só tenha 1 elemento
    if(!aux->next){
        reset_list(l);
        return;
    }

    // c.c.
    while(aux->next->next){
        aux = aux->next;
    }
    free(aux->next);
    aux->next = NULL;
}

/**************************************/
void reset_list(Node** l){
    Node* aux = *l;

    while(aux){
        *l = aux->next;
        free(aux);
        aux = *l;
    }

    *l = create_list();
}

/**************************************/
void show_list(Node* l){
    if(is_empty(l)){
        printf("List is empty!\n");
        return;
    }

    Node* aux = l;
    printf("List: [ ");
    for(; aux; aux = aux->next){
        printf("%d%s", aux->info, (aux->next ? ", ":" ]\n"));
    }
}

/////// IMPLEMENTAÇÃO DAS FUNÇÕES DO EXERCÍCIO ///////

int sizeof_list(Node* l){
    int n = 0;
    Node* aux = l;
    while(aux){
        n++;
        aux = aux->next;
    }
    return n;
}

/**************************************/
int biggests(Node* l, int value){
    int n = 0;
    Node* aux = l;
    while(aux){
        if(aux->info > value)
            n++;
        aux = aux->next;
    }
    return n;
}

/**************************************/
Node* last_elem(Node* l){
    Node* aux = l;
    while(aux->next){
        aux = aux->next;
    }
    return aux;
}

/**************************************/
Node* concat_lists(Node* l1, Node* l2){
    Node* aux = l1;
    Node* l3 = create_list();

    while(aux){
        push_back(&l3, aux->info);
        aux = aux->next;
    }
    aux = l2;
    while(aux){
        push_back(&l3, aux->info);
        aux = aux->next;
    }

    return l3;
}

/**************************************/
void remove_val(Node** l, int n){
    if(is_empty(*l)) return;
    
    Node* aux = *l;

    // caso o valor seja o primeiro
    if(aux->info == n){
        *l = aux->next;
        free(aux);
        return;
    }

    // caso esteja após o primeiro
    while(aux){
        if(aux->next->info == n){
            Node* bux = aux->next->next;
            free(aux->next);
            aux->next = bux;
            return;
        }
        aux = aux->next;
    }
}

/**************************************/
void remove_all_vals(Node** l, int value){
    if(is_empty(*l)) return;

    Node* aux = *l;
    Node* bux = aux->next;

    // se os primeiros elementos forem iguais ao valor 
    while(aux->info == value){
        *l = aux->next;
        free(aux);
        aux = *l;
        bux = aux->next;
    }
    // a partir de então
    while(bux){
        if(bux->info == value){
            aux->next = bux->next;
            free(bux);
            bux = aux->next;
        }else{
            aux = bux;
            bux = bux->next;
        }
    }

    // se o último/único elemento for igual ao valor 
    if(aux->info == value){
        *l = aux->next;
        free(aux);
    }
}

/**************************************/
Node* separetes_list(Node** l, int value){
    if(is_empty(*l)) return create_list();

    Node* l2 = create_list();

    Node* aux = *l;
    while(aux){
        if(aux->info == value){
            l2 = aux->next;
            aux->next = NULL;
            break;
        }
        aux = aux->next;
    }

    return l2;
}

/**************************************/
Node* merge_lists(Node* l1, Node* l2){
    Node* l3 = create_list();
    Node* aux1 = l1;
    Node* aux2 = l2;
    int n = 0; // vai variar entre 0 e 1 para alterar entre a lista 1 e a lista 2

    // enquanto houverem elementos nas duas listas
    while(aux1 && aux2){
        if(!n){
            push_back(&l3, aux1->info);
            aux1 = aux1->next;
            n = 1;
        }else{
            push_back(&l3, aux2->info);
            aux2 = aux2->next;
            n = 0;
        }
    }

    // se a lista 2 acabar
    while(aux1){
        push_back(&l3, aux1->info);
        aux1 = aux1->next;
    }

    // se a lista 2 acabar
    while(aux2){
        push_back(&l3, aux2->info);
        aux2 = aux2->next;
    }

    return l3;
}

/**************************************/
Node* invert_list(Node* l){
    if(is_empty(l)) return create_list();
    Node* l2 = create_list();

    Node* aux = l; 
    while(aux){
        push_front(&l2, aux->info);
        aux = aux->next;
    }

    return l2;
}

int equals(Node* l1, Node* l2){
    Node* aux1 = l1;
    Node* aux2 = l2;

    while(aux1 && aux2){
        if(aux1->info != aux2->info){
            return 0;
        }
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    // se alguma das listas ainda contiver elementos, as listas são diferentes
    if(aux1 || aux2){
        return 0;
    }

    return 1;
}

/**************************************/
Node* copy_list(Node* l){
    if(is_empty(l)) return create_list();
    Node* l2 = create_list();
    Node* aux = l;

    while(aux){
        push_back(&l2, aux->info);
        aux = aux->next;
    }

    return l2;
}