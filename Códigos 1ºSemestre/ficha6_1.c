#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING 50
#define MAX_ESTUDANTES 100
typedef struct{
    int numero;
    char nome[MAX_STRING];
    int nota;
}tipoEstudante;
int lerQuantidadeEstudantes();
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
void limpaBufferStdin(void);
tipoEstudante lerDadosEstudante();
void lerNotas(tipoEstudante v[MAX_ESTUDANTES], int limite);
void mostrarDados(tipoEstudante v[MAX_ESTUDANTES], int limite);
int main()
{
    int i,numEstudantes;
    tipoEstudante turma[MAX_ESTUDANTES];
    numEstudantes=lerQuantidadeEstudantes();
    for(i=0;i<numEstudantes;i++){
        turma[i]=lerDadosEstudante();
    }
    mostrarDados(turma, numEstudantes);
    lerNotas(turma, numEstudantes);
    mostrarDados(turma, numEstudantes);
    return 0;
}
void lerNotas(tipoEstudante v[MAX_ESTUDANTES], int limite){
    int i;
    for(i=0;i<limite;i++){
        printf("Estudante: %d  - %s", v[i].numero, v[i].nome);
        v[i].nota=lerInteiro("Indique nota ", 0,20);
    }
}
void mostrarDados(tipoEstudante v[MAX_ESTUDANTES], int limite){
    int i;
    for(i=0;i<limite;i++){
        printf("Numero: %d   Nome: %s", v[i].numero, v[i].nome);
        if(v[i].nota!=-1){
            printf("Nota: %d", v[i].nota);
        }
    }
}
tipoEstudante lerDadosEstudante(){
    tipoEstudante e;
    int num;
    e.numero=lerInteiro("Indique numero ", 1,9999);
    printf("Indique nome ");
    fgets(e.nome, MAX_STRING, stdin);
    e.nota=-1;
    return e;
}
int lerQuantidadeEstudantes(){
    int quant;
    quant=lerInteiro("Quantidade de estudantes ", 1,MAX_ESTUDANTES);
    return quant;
}
// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)
        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {
            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }
        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);
    return numero;
}
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();
        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {
            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }
        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);
    return numero;
}
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;
    do          // Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);
        tamanhoString = strlen(vetorCaracteres);
        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }
    }
    while (tamanhoString == 1);
    if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0';    //Elimina o \n da string armazenada em vetor
    }
}
void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
/*
tipoData lerData(void)
{
    tipoData data;
    int maxDiasMes;
    printf("\n Data da Avaliacao");
    data.ano = lerInteiro(" ano", 2014, 2016);
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
*/