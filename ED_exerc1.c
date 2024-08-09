/*
Exerc�cio de ESTRUTURA DE DADOS, prof� Liliane Machado

C�digo: Herick Jos� de Freitas

:: Crie um c�digo que calcule o n-�simo termo da sequ�ncia de Fibonacci
   - usar fun��o para calcular o valor da sequ�ncia
   - n�o use recurs�o
   - main possuir apenas 3 vari�veis locais
   - Utilize passagem de par�metro por refer�ncia
*/

#include <stdio.h>


void next_value(int*, int);

int main(){

    int n, i = 1, last_value = i;

    scanf("%d", &n);
    printf("Sequencia de Fibonacci ate o %d valor:\n", n);

    printf("%d,", i);

    for(; n>1; n--){
        last_value = i;
        printf(" %d%c", i, n==2 ? '.':',');
        next_value(&i, last_value);
    }

    return 0;
}

void next_value(int *i, int current_value){
    *i = (*i) + current_value;
}






/*
IMPRIMIR TABELA ASCII:

void imprime(unsigned char);

int main(void){
    unsigned char c = 0;
    for(; c < 255; c++)
          imprime(c);
    imprime(c);

    return 0;
}

void imprime(unsigned char c){
     printf("\n%d - %c", c, c);
}
*/

