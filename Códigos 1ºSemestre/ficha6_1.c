#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 50
#define MAX_ESTUDANTES 100
typedef struct 
{
    int numero;
    char nome[255];
    int nota;
}tipoEstudante;

int lerInteiro(int minimo, int maximo);
void limpaBufferStdin(void);
int main()
{
    tipoEstudante turma[MAX_ESTUDANTES];
    estudante.numero = lerInteiro(1,9999);
    fgets(estudante.nome, MAX_STRING, stdin);
    printf("\nNome: %s", estudante.nome);
    printf("Numero: %d", estudante.numero);
    return 0;
}


int lerInteiro(int minimo, int maximo) {
    int numero, controlo;
    do {
        printf("Indique valor (%d a %d) :", minimo, maximo);
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

void limpaBufferStdin(void) {
    char chr;
    do {
        chr = getchar();
    } while (chr != '\n' && chr != EOF);
}