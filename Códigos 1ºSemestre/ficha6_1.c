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
} tipoEstudante;

int lerInteiro(int minimo, int maximo);
void limpaBufferStdin(void);
int lerQuantidadeEstudantes();
tipoEstudante lerDadosEstudante();
int main()
{
    int numEstudantes;

    tipoEstudante turma[MAX_ESTUDANTES];
    numEstudantes = lerQuantidadeEstudantes();
    for (int i = 0; i < numEstudantes; i++)
    {
        turma[0] = lerDadosEstudante();
    }
    printf("Numero: \n%d  Nome: %s", turma[0].numero, turma[0].nome);
    return 0;
}

tipoEstudante lerDadosEstudante()
{
    tipoEstudante e;
    int num;
    printf("Indique numero: ");
    num = lerInteiro(1, 9999);
    printf("Indique nome ");
    fgets(e.nome, MAX_STRING, stdin);
    return e;
}

int lerInteiro(int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("Indique valor (%d a %d) :", minimo, maximo);
        controlo = scanf("%d", &numero); // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();              //limpa todos os caracteres do buffer stdin (nomeadamente o \n)
        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {
            if (numero < minimo || numero > maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }
        }
    } while (numero < minimo || numero > maximo || controlo == 0);
    return numero;
}

void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    } while (chr != '\n' && chr != EOF);
}

int lerQuantidadeEstudantes()
{
    int quant;

    printf("Indique quantidade de estudantes: ");
    quant = lerInteiro(1, MAX_ESTUDANTES);

    return quant;
}