#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesAuxiliares.h"


int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo) {
    int numero, controlo;
    do {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0) {
            printf("Devera inserir um numero inteiro \n");
        } else {

            if(numero<minimo || numero>maximo) {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    } while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo) {
    float numero;
    int controlo;
    do {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0) {
            printf("Devera inserir um numero decimal (float) \n");
        } else {

            if(numero<minimo || numero>maximo) {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    } while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING],
               char vetorCaracteres[MAX_STRING],
               int maximoCaracteres) {
    int tamanhoString;

    do {		// Repete leitura caso sejam obtidas strings vazias
        //   puts(mensagem);
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1) {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }

    } while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n') { // ficaram caracteres no buffer....
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    } else {
        vetorCaracteres[tamanhoString-1] ='\0';          //substitui \n da string armazenada em vetor por \0 (evitar problemas com listagens)
    }
}

void limpaBufferStdin(void) {
    char chr;
    do {
        chr = getchar();
    } while (chr != '\n' && chr != EOF);
}

tipoData lerData(void) {
    tipoData data;
    int maxDiasMes;

    data.ano = lerInteiro(" ano", 2014, 2020);
    data.mes = lerInteiro(" mes", 1, 12);

    switch (data.mes) {
    case 2:
if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0)) {
            maxDiasMes = 29;
        } else {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(" dia:", 1, maxDiasMes);
    return data;
}





