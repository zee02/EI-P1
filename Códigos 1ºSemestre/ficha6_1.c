#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define MAX_STRING 50
#define MAX_ESTUDANTES 100
typedef struct
{
    int dia, mes, ano;
} tipoData;
typedef struct
{
    int numero;
    char nome[MAX_STRING];
    int nota;
    tipoData data;
} tipoEstudante;
int lerQuantidadeEstudantes();
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);
tipoEstudante lerDadosEstudante();
void lerNotas(tipoEstudante v[MAX_ESTUDANTES], int limite);
void mostrarDados(tipoEstudante v[MAX_ESTUDANTES], int limite);
char menu(int numE, int numAvaliados);
int procura(int numAProcurar, tipoEstudante v[], int quant);
void contas(tipoEstudante v[MAX_ESTUDANTES], int *quantEstudantes, float *percPosi, int numAvaliados);

int main()
{
    int i, numEstudantes = 0, aux, posicao, num, numAvaliados = 0;
    tipoEstudante turma[MAX_ESTUDANTES];
    char opcao;
    setlocale(LC_ALL, "");
    do
    {
        opcao = menu(numEstudantes, numAvaliados);
        switch (opcao)
        {
        case 'A':
            if (numEstudantes < MAX_ESTUDANTES)
            {
                aux = lerInteiro("Indique numero ", 1, 9999);
                posicao = procura(aux, turma, numEstudantes);
                if (posicao != -1)
                {
                    turma[numEstudantes].numero = aux;
                    lerString("Indique nome ", turma[numEstudantes].nome, MAX_STRING);
                    numEstudantes++;
                }
                else
                {
                    printf("Número já existe");
                }
            }
            else
            {
                printf("Já não há espaço\n");
            }
            break;

        case 'I':
            if (numEstudantes == 0)
            {
                printf("Não há estudantes...\n");
            }
            else
            {
                num = lerInteiro("Indique número do estudante ", 1, 9999);
                posicao = procura(num, turma, numEstudantes);
                if (posicao != -1)
                {
                    printf("Estudante %s ", turma[posicao].nome);
                    turma[posicao].nota = lerInteiro("Indique nota ", 0, 20);
                    turma[posicao].data = lerData();
                    if (turma[posicao].nota == -1)
                    {
                        numAvaliados++;
                    }
                }
                else
                {
                    printf("Não existe estudante com nota ");
                }
            }
            break;
        case 'M':
            mostrarDados(turma, numEstudantes);
            break;
        }
    } while (opcao != 'F');

    // numEstudantes=lerQuantidadeEstudantes();
    // for(i=0;i<numEstudantes;i++){
    //     turma[i]=lerDadosEstudante();
    // }
    // mostrarDados(turma, numEstudantes);
    // lerNotas(turma, numEstudantes);
    // mostrarDados(turma, numEstudantes);
    return 0;
}

int procura(int numAProcurar, tipoEstudante v[], int quant)
{
    int pos = -1;
    for (int i = 0; i < quant; i++)
    {
        if (v[i].numero == numAProcurar)
        {
            pos = i;
            i = quant;
        }
    }
    return pos;
}
char menu(int numE, int numAvaliados)
{
    char op;
    printf("\n\n************************ Menu Principal ************************\n");
    printf("Estudantes Inseridos: %2d\n", numE);
    printf("Estudantes Avaliados: %2d\n", numAvaliados);
    printf("Notas Positivas (%): ***.**\n");
    printf("A - Acrescenta Estudante\n");
    printf("I - Introdução Notas\n");
    printf("M - Mostrar Dados\n");
    printf("G - Gravar dados em ficheiros L – Ler dados de ficheiro\n");
    printf("F - Fim\n");
    printf("Opcao--> ");

    scanf("%c", &op);
    limpaBufferStdin();
    op = toupper(op);
    return op;
}

void contas(tipoEstudante v[MAX_ESTUDANTES], int *quantEstudantes, float *percPosi, int numAvaliados)
{
    int numaval = 0, positivas = 0;
    for (int i = 0; i < numAvaliados; i++)
    {
        if (v[i].nota == -1)
        {
            numaval++;
            if(v[i].nota >= 10){
                positivas++;
            }
        }
    }
    *quantEstudantes=numaval;
    if(numaval!=0){
    *percPosi=(float)positivas/numaval;
    }
}

void lerNotas(tipoEstudante v[MAX_ESTUDANTES], int limite)
{
    int i;
    for (i = 0; i < limite; i++)
    {
        printf("Estudante: %d  - %s", v[i].numero, v[i].nome);
        v[i].nota = lerInteiro("Indique nota ", 0, 20);
    }
}
void mostrarDados(tipoEstudante v[MAX_ESTUDANTES], int limite)
{
    int i;
    for (i = 0; i < limite; i++)
    {
        printf("\nNome: %s    Numero: %d \n", v[i].nome, v[i].numero);
        if (v[i].nota != -1)
        {
            printf("Nota: \n%d  ", v[i].nota);
            printf("Data: %d-%d-%d", v[i].data.dia, v[i].data.mes, v[i].data.ano);
        }
    }
}

tipoEstudante lerDadosEstudante()
{
    tipoEstudante e;
    int num;
    e.numero = lerInteiro("Indique numero ", 1, 9999);
    lerString("Indique nome: ", e.nome, MAX_STRING);
    e.nota = -1;
    return e;
}
int lerQuantidadeEstudantes()
{
    int quant;
    quant = lerInteiro("Quantidade de estudantes ", 1, MAX_ESTUDANTES);
    return quant;
}
// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
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
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf("%f", &numero); // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();
        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
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
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;
    do // Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);
        tamanhoString = strlen(vetorCaracteres);
        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n"); // apenas faz sentido limpar buffer se a ficarem caracteres
        }
    } while (tamanhoString == 1);
    if (vetorCaracteres[tamanhoString - 1] != '\n') // ficaram caracteres no buffer....
    {
        limpaBufferStdin(); // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString - 1] = '\0'; //Elimina o \n da string armazenada em vetor
    }
}
void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    } while (chr != '\n' && chr != EOF);
}

tipoData lerData(void)
{
    tipoData data;
    int maxDiasMes;
    printf("\n Data da Avaliacao");
    data.ano = lerInteiro(" ano", 2021, 2022);
    data.mes = lerInteiro(" mes", 1, 12);
    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
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
