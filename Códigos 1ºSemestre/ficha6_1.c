#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 50
#define MAX_ESTUDANTES 100
typedef struct
{
    int numero;
    char nome[MAX_STRING];
    int nota;
} tipoEstudante;
int lerInteiro(int minimo, int maximo);
void limpaBufferStdin(void);
void lerNotas(tipoEstudante v[MAX_ESTUDANTES], int limite);
void mostrarDados(tipoEstudante v[MAX_ESTUDANTES], int limite);
tipoEstudante lerDadosEstudante();
int lerQuantidadeEstudantes();
int lerInteiro(int minimo, int maximo);
void limpaBufferStdin(void);

int main()
{
    int numEstudantes;
    tipoEstudante turma[MAX_ESTUDANTES];
    numEstudantes = lerQuantidadeEstudantes();
    for (int i = 0; i < numEstudantes; i++)
    {
        turma[i] = lerDadosEstudante();
    }
    mostrarDados(turma, numEstudantes);
    lerNotas(turma, numEstudantes);
    mostrarDados(turma, numEstudantes);
    return 0;
}
void lerNotas(tipoEstudante v[MAX_ESTUDANTES], int limite)
{
    int i;
    for (i = 0; i < limite; i++)
    {
        printf("Estudante: %d  - %s", v[i].numero, v[i].nome);
        v[i].nota = lerInteiro(0, 20);
    }
}
void mostrarDados(tipoEstudante v[MAX_ESTUDANTES], int limite)
{
    int i;
    for (i = 0; i < limite; i++)
    {
        printf("Numero: %d   Nome: %s", v[i].numero, v[i].nome);
        if (v[i].nota != -1)
            printf("Nota: %d", v[i].nota);
    }
}
tipoEstudante lerDadosEstudante()
{
    tipoEstudante e;
    int num;
    printf("Indique numero ");
    e.numero = lerInteiro(1, 9999);
    printf("Indique nome ");
    fgets(e.nome, MAX_STRING, stdin);
    e.nota = -1;
    return e;
}

int lerQuantidadeEstudantes()
{
    int quant;
    printf("Quantidade de estudantes");
    quant = lerInteiro(1, MAX_ESTUDANTES);
    return quant;
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