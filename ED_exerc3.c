// PROGRAMA QUE CONTA AS VOGAIS DE UMA ENTRADA
// Profª:    Liliane Machado;
// Discente: Herick José de Freitas


#include <stdio.h>

int main(){

    char str[100];
    int i = 0, v = 0;

    printf("Type a phrase to get the vowels amount (end with a \".\"; max: 100 chars):\n");

    do{
        scanf("%c", &str[i]); //Lê caractere por caractere

        switch(str[i]){       //conta as vogais assim que lidas
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                v++;
                break;
            default: break;
        }
        i++;

    }while(str[i-1]!='.' && i<99); // quebra o loop se houver um terminador '.' ou chegar no limite do vetor

    str[i] = '\0';                 // adicionar o encerrador de string no lugar do '.'

    printf("\nVowels: %i\n", v);   // dar saída na quantidade de vogais

    return 0;
}
