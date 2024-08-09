//INICIO DO USO DE ALOCA��O DIN�MICA
//Prof�: Liliane Machado
//Aluno: Herick Jos� de Freitas

#include <stdio.h>
#include <stdlib.h>

void main(){

    int *p; // declarando um ponteiro para apontar para o endere�o a ser reservado

    printf("Valor de p antes: %d\n", *p);
    printf("Endereco apontado por p antes: %p\n", p);


    p = (int*) malloc(sizeof(int)); // alocando dinamicamente um espa�o de 2B na mem�ria e salvando o endere�o no ponteiro p


    if(!*p){           // checando se a mem�ria foi alocada como solicitado, caso contr�rio, encerra-se o programa
        return;
    }

    scanf("%d", p);   // l� um valor int e armazena na memoria alocada

    printf("Valor de p depois: %d\n", *p);  //novo valor apontado por p (que est� armazenado no espa�o reservado)
    printf("Endereco apontado por p depois: %p\n", p); //endere�o alocado

    free(p);

    printf("\n");
    printf("Valor de p apos FREE(): %d\n", *p);
    printf("Endereco apontado por p apos FREE(): %p\n", p);

    return;
}
