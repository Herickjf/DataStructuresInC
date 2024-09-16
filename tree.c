/*
    Implementação de Árvores Binárias
    Autor: Herick José de Freitas
*/
#include <stdio.h>
#include <stdlib.h>

// struct arvore
/*
    árvore: contém ramificações e não tem árvore pai                (não é ramificação de outra árvore)
    sub árvore: contém ramificações e tem árvore/sub árvore pai     (é ramificação de outra árvore)
    folha: não contém ramificações e contém árvore/sub árvore pai   (é ramificação de outra árvore)
*/
struct tree{
    char c;
    struct tree* left;
    struct tree* right;
};
typedef struct tree Tree;


// protótipo das funções
Tree* create_tree(char, Tree*, Tree*);          // retorna o ponteiro de uma árvore, recebendo um char identificador e duas ramificações
Tree* create_empty_tree();                      // retorna uma árvore vazia, usada nas ramificações das folhas
void show(Tree*);                               // mostra a árvore com a notação de arvore


///////////////////////////////////////////////////
int main(){
    Tree* t = create_tree('a', // nome da arvore
                          // ramificação da esquerda
                          create_tree('b', // nome da sub arvore
                                      // ramificação da esquerda (folha)
                                      create_tree('d', 
                                                  create_empty_tree(), 
                                                  create_empty_tree()
                                                  ),
                                      // ramificação da direita (nula)
                                      create_empty_tree()
                                      ),
                          // ramificação da direita
                          create_tree('c', // nome da sub árvore
                                      // ramificação da esquerda (folha)
                                      create_tree('e',
                                                  create_empty_tree(),
                                                  create_empty_tree()
                                                  ),
                                      // ramificação da esquerda (folha)
                                      create_tree('f',
                                                  create_empty_tree(),
                                                  create_empty_tree()
                                                  )
                                      )
                          );  

    show(t);

    return 0;
}

///////////////////////////////////////////////////
Tree* create_tree(char c, Tree* tl, Tree* tr){
    Tree* t = (Tree*) malloc(sizeof(Tree));
    if(t){
        t->c = c;
        t->left = tl;
        t->right = tr;
    }
    return t;
}

///////////////////////////////////////////////////
Tree* create_empty_tree(){
    return NULL;
}

///////////////////////////////////////////////////
void show(Tree* t){
    printf("<");
    if(t){
        printf("%c", t->c);
        show(t->left);
        show(t->right);
    }else{
        printf(" ");
    }
    printf(">");
}