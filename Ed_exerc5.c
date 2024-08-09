//EXERC�CIO DE ALOCA��O DIN�MICA
//Prof.�: Liliane Machado
//Aluno:  Herick Jos� de Freitas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(char *);                      // faz um scanf char a char e encerra a leitura com um '\0'

void main(void){

    char *p[10], nome[150];             // definindo um vetor de ponteiros para apontar as mem�rias dinamicamente alocadas e uma variavel para receber as entradas

    FILE *arq;
    arq = fopen("namesFile.txt", "w");  // solicitando a cria��o de um arquivo para, posteriormente, salvar essas entradas
    if(!arq){                           // verificando se o arquivo foi aberto corretamente
            printf("File was'nt opend correctly.");
        return;
    }
    fprintf(arq, "NAME,STR_SIZE\n\n"); // imprimindo o cabe�alho do txt

    printf("Type 10 names (max 150 chars) to save them in a file named \"namesFile.txt\":\n");


    for(int i = 0; i<10; i++){          // repetindo o processo de leitura, aloca��o de mem�ria e salvamento no arquivo 10 vezes

        printf("%d: ", i+1);
        read(nome);                     // l� a entrada

        p[i] = (char**) malloc((strlen(nome) + 1) * sizeof(char)); // solicita a aloca��o de mem�ria do tamanho da entrada lida(em Bytes)

        if(p[i] == 0){                      // caso n�o seja alocada a mem�ria
            for(i = i-1; i>=0; i--){
                free(p[i]);             // libera cada espa�o alocado anteriormente(se foi)
            }
            printf("Error :\\");
            return;                     // encerra o programa
        }                               // caso seja alocada a mem�ria corretamente:

        strcpy(p[i], nome);            // copia na mem�ria alocada dinamicamente a entrada lida
        fprintf(arq, "%s, %d\n", p[i], strlen(p[i])); // salva no arquivo o nome que foi copiado na mem�ria e seu temanho (a fim de comparar os tamanhos das entredas armazenadas)
    }


    for(int i = 0; i<10; i++)           // libera a mem�ria reservada
        free(p[i]);

    fclose(arq);                        // fecha o arq aberto
    return;
}

void read(char *str){
    int j = 0;
    do{                                 // recebe cada entrada
        scanf("%c", &str[j]);
        j++;
    }while(str[j-1] != '\n' && j<150);
    str[j-1] = '\0';                    // encerra a string
    return;
}
