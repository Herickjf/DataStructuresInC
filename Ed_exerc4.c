//INICIO DO USO DE ALOCAÇÃO DINÂMICA
//Profª: Liliane Machado
//Aluno: Herick José de Freitas

#include <stdio.h>
#include <stdlib.h>

void main(){

    int *p; // declarando um ponteiro para apontar para o endereço a ser reservado

    printf("Valor de p antes: %d\n", *p);
    printf("Endereco apontado por p antes: %p\n", p);


    p = (int*) malloc(sizeof(int)); // alocando dinamicamente um espaço de 2B na memória e salvando o endereço no ponteiro p


    if(!*p){           // checando se a memória foi alocada como solicitado, caso contrário, encerra-se o programa
        return;
    }

    scanf("%d", p);   // lê um valor int e armazena na memoria alocada

    printf("Valor de p depois: %d\n", *p);  //novo valor apontado por p (que está armazenado no espaço reservado)
    printf("Endereco apontado por p depois: %p\n", p); //endereço alocado

    free(p);

    printf("\n");
    printf("Valor de p apos FREE(): %d\n", *p);
    printf("Endereco apontado por p apos FREE(): %p\n", p);

    return;
}
