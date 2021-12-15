#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define MAX_STRING 50
#define MAX_ESTUDANTES 100
#define MAX_RESERVAS 100
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

typedef struct
{
    int codigoR;
    int numEstudante;
    tipoData dataR;
    int tipoR;
} tipoReserva;

tipoData lerData(void);
int lerQuantidadeEstudantes();
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
void limpaBufferStdin(void);
tipoEstudante lerDadosEstudante();
void lerNotas(tipoEstudante v[MAX_ESTUDANTES], int limite);
void mostrarDados(tipoEstudante v[MAX_ESTUDANTES], int limite);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
char menu(int, int, float);
int procura(int numAProcurar, tipoEstudante v[], int quant);
void contas(int *numA, float *percPos, tipoEstudante v[], int quant);
void leFicheiroBinario(tipoEstudante v[], int *quant);
void gravaFicheiroBinario(tipoEstudante v[], int quant);
void gravaFicheiroTexto(tipoEstudante v[MAX_ESTUDANTES], int limite);
void eliminaReserva();
int main()
{
    int i, numEstudantes = 0, aux, posicao, num, numAvaliados = 0;
    int numReservas = 0;
    tipoEstudante turma[MAX_ESTUDANTES];
    tipoReserva reservas[MAX_RESERVAS];
    char opcao;
    float percPositivas;
    setlocale(LC_ALL, "");
    do
    {
        contas(&numAvaliados, &percPositivas, turma, numEstudantes);
        opcao = menu(numEstudantes, numAvaliados, percPositivas);
        switch (opcao)
        {
        case 'A':
            if (numEstudantes < MAX_ESTUDANTES)
            {
                aux = lerInteiro("Indique numero ", 1, 9999);
                posicao = procura(aux, turma, numEstudantes);
                if (posicao == -1)
                {
                    turma[numEstudantes].numero = aux;
                    lerString("Indique nome ", turma[numEstudantes].nome, MAX_STRING);
                    turma[numEstudantes].nota = -1;
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
                }
                else
                {
                    printf("Não existe estudante com esse número");
                }
            }
            break;
        case 'M':
            mostrarDados(turma, numEstudantes);
            break;
        case 'G':
            gravaFicheiroBinario(turma, numEstudantes);
            break;
        case 'L':
            leFicheiroBinario(turma, &numEstudantes);
            break;
        case 'T':
            gravaFicheiroTexto(turma, numEstudantes);
            break;

        case 'E':
            eliminaReserva(turma, numEstudantes);
            break;

        case 'R':
            if (numReservas < MAX_RESERVAS && numEstudantes > 0)
            {
                aux = lerInteiro("Indique numero ", 1, 9999);
                posicao = procura(aux, turma, numEstudantes);
                if (posicao != -1)
                {
                    reservas[numReservas].numEstudante = aux;
                    do
                    {
                        lerString("Indique numero da reserva ", turma[numEstudantes].nome, MAX_STRING);
                        posicao = procuraR(aux,reservas,numReservas);
                    } while ();
                    turma[numEstudantes].nota = -1;
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
        }
    } while (opcao != 'F');
    return 0;
}
void gravaFicheiroBinario(tipoEstudante v[], int quant)
{
    FILE *fich;
    fich = fopen("estudantes.dat", "wb");
    if (fich != NULL)
    {
        fwrite(&quant, sizeof(int), 1, fich);
        fwrite(v, sizeof(tipoEstudante), quant, fich); //podem-se fazer mais validações nos fwrite
        fclose(fich);
    }
    else
    {
        printf("\n*** ERRO A ABRIR FICHEIRO ***\n");
    }
}
void leFicheiroBinario(tipoEstudante v[], int *quant)
{
    FILE *fich;
    fich = fopen("estudantes.dat", "rb");
    if (fich != NULL)
    {
        fread(&*quant, sizeof(int), 1, fich);
        fread(v, sizeof(tipoEstudante), *quant, fich); //podem-se fazer mais validações nos fread
        fclose(fich);
    }
    else
    {
        printf("\n*** ERRO A ABRIR FICHEIRO ***\n");
    }
}
void gravaFicheiroTexto(tipoEstudante v[MAX_ESTUDANTES], int limite)
{
    FILE *fich;
    int i;
    fich = fopen("estudantes.txt", "w");
    if (fich != NULL)
    {
        for (i = 0; i < limite; i++)
        {
            fprintf(fich, "\nNome: %s     Numero: %d \n", v[i].nome, v[i].numero);
            if (v[i].nota != -1)
            {
                fprintf(fich, "Nota: %d   ", v[i].nota);
                fprintf(fich, "Data: %d-%d-%d", v[i].data.dia, v[i].data.mes, v[i].data.ano);
            }
        }
        printf("\nDados gravados no ficheiro\n");
        fclose(fich);
    }
    else
    {
        printf("\n*** ERRO A ABRIR FICHEIRO ***\n");
    }
}

void contas(int *numA, float *percPos, tipoEstudante v[], int quant)
{
    int i, numAval = 0, positivas = 0;
    for (i = 0; i < quant; i++)
    {
        if (v[i].nota != -1)
        {
            numAval++;
            if (v[i].nota >= 10)
            {
                positivas++;
            }
        }
    }
    *numA = numAval;
    if (numAval != 0)
    {
        *percPos = (float)positivas / numAval * 100;
    }
}
int procuraR(int numAProcurar, tipoEstudante v[], int quant)
{
    int pos = -1, i;
    for (i = 0; i < quant; i++)
    {
        if (v[i].numero == numAProcurar)
        {
            pos = i;
            i = quant;
        }
    }
    return pos;
}
int procura(int numAProcurar, tipoEstudante v[], int quant)
{
    int pos = -1, i;
    for (i = 0; i < quant; i++)
    {
        if (v[i].numero == numAProcurar)
        {
            pos = i;
            i = quant;
        }
    }
    return pos;
}
char menu(int numE, int numA, float percPos)
{
    char op;
    printf("\n\n************************ Menu Principal ************************\n");
    printf("Estudantes Inseridos: %2d\n", numE);
    printf("Estudantes Avaliados: %2d Notas Positivas (%%): %6.2f\n", numA, numA == 0 ? 0 : percPos);
    printf("A - Acrescenta Estudante\n");
    printf("R - Adicionar reserva\n");
    printf("E - Eliminar Reserva\n");
    printf("I - Introdução Notas\n");
    printf("M - Mostrar Dados\n");
    printf("G - Gravar dados em ficheiro\n");
    printf("L - Ler dados de ficheiro\n");
    printf("T - Gravar dados em ficheiro de texto\n");
    printf("F - Fim\n");
    printf("Opcao-->  ");
    scanf("%c", &op);
    limpaBufferStdin();
    op = toupper(op);
    return op;
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
        printf("\nNome: %s     Numero: %d \n", v[i].nome, v[i].numero);
        if (v[i].nota != -1)
        {
            printf("Nota: %d   ", v[i].nota);
            printf("Data: %d-%d-%d", v[i].data.dia, v[i].data.mes, v[i].data.ano);
        }
    }
}
tipoEstudante lerDadosEstudante()
{
    tipoEstudante e;
    int num;
    e.numero = lerInteiro("Indique numero ", 1, 9999);
    lerString("Indique nome ", e.nome, MAX_STRING);
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

void eliminaReserva() {

}