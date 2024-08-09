/*
Disciplina: Estrutura de Dados
Profª:      Liliane Machado
Discente:   Herick José de Freitas


Exercício 2

PROGRAMA 1)
    Ler "primeiro nome" e "idade" de n pessoas
    Guardar dados em um arquivo-texto

PROGRAMA 2)
    Mostrar o nome das pessoas maiores de 18 anos

PROGRAMA 3)
    Ordenar os nomes (com respectivas idades)
    Salvar em um arquivo
*/


#include <stdio.h>
#include <string.h>



void flush_in(); // Limpa o buffer após leitura de string
void ordena(char lista[][20], int);



int main(){

    int n, idade;
    char nome[15];
    FILE *arquivo;
    FILE *arqOrdenado;


    // REGISTRAR PESSOAS
    {

        printf("How many people will you register? ");
        scanf("%i", &n);  // lê a quantidade de registros a serem feitos

        arquivo = fopen("Registers.txt", "w");   // tenta apontar para o arquivo de escrita (criar)
        if(arquivo == NULL){
            printf("Could'nt create the file.");   // encerra o programa caso não seja possível abrir o arquivo
            return 0;
        }

        for(int i = 1; i <=n; i++){
                //leitura dos dados que irão preencher o arquivo
            printf("REGISTER %i:\n\tFirst Name - ", i);
            scanf("%s", nome);
            flush_in();
            printf("\tAge - ");
            scanf("%i", &idade);
                //escrita dos dados recebidos
            fprintf(arquivo, "%s %i \n", nome, idade);

            printf("\n");
        }

        //fechamento do arquivo aberto anteriormente
        fclose(arquivo);

    }
//---------------------------------------------------------------

    char lista[n][20]; // utilizado na parte de ordenação da lista


    // FILTRAR MAIORES DE IDADE
    {
        arquivo = fopen("Registers.txt", "r");   // tenta apontar para o arquivo de leitura
        if(arquivo == NULL){
            printf("Could'nt open the file.");   // encerra o programa caso não seja possível abrir o arquivo
            return 0;
        }


        // mostrar os maiores de idade do arquivo
        printf("\nPEOPLE OF LEGAL AGE IN YOUR REGISTER:\n");

       int i = 0;
       while((fscanf(arquivo, "%s %d\n", nome, &idade)) != EOF ){ // caso o fscanf não retorne o valor da constante EOF (-1), a leitura continua



            if(idade >= 18){
                printf("\t%s, %i years\n", nome, idade);
            }

            //salvando a lista dos nomes (com idade) para ordenar em seguida
            sprintf(lista[i], "%s %d", nome, idade);
            i++;

        }

        fclose(arquivo);
    }
//-------------------------------------------------------------

    // ORGANIZAR PELA ORDEM ALFABÉTICA
    {

        arqOrdenado = fopen("NewRegisters.txt", "w");   // tenta apontar para o arquivo de escrita (criar)
        if(arqOrdenado == NULL){
            printf("Could'nt create the file.");   // encerra o programa caso não seja possível abrir o arquivo
            return 0;
        }


        ordena(lista, n);

        for(int i=0; i<n; i++){
            fprintf(arqOrdenado, "%s\n", lista[i]);
        }

        fclose(arqOrdenado);

    }


    return 0;
}

//********************************************************************************

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

//-------------------------------------------------------

void ordena(char lista[][20], int n){

    char nomeTemp[20];
    int r;

    for(int x = 0; x < n; x++){
        for(int y = x+1; y < n; y++){
            r = strcmp(lista[x], lista[y]);
            if(r>0){
                strcpy(nomeTemp, lista[x]);
                strcpy(lista[x], lista[y]);
                strcpy(lista[y], nomeTemp);
            }
        }
    }
}
