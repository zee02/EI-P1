#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_estudantes 25
int leQuantidadeAvaliados();
float calculaMedia(int v[], int num);
void mostrarDados(int v[max_estudantes], int num);
void lerNotas(int v[], int num);
void alterarNota(int v[], int num);
void notasPositivas(int v[], int num);
int main()
{
    int notas[max_estudantes];
    int numEstudantes;
    float media;

    numEstudantes = leQuantidadeAvaliados();
    lerNotas(notas, numEstudantes);
    mostrarDados(notas, numEstudantes);
    media = calculaMedia(notas, numEstudantes);
    alterarNota(notas, numEstudantes);
    mostrarDados(notas, numEstudantes);
    notasPositivas(notas, numEstudantes);

    printf("Media = %.1f", media);

    return 0;
}

float calculaMedia(int v[], int num)
{
    int i, soma = 0;
    float media;
    for (int i = 0; i < num; i++)
    {
        soma += v[i];
    }
    media = (float)soma / num;
    return media;
}

int leQuantidadeAvaliados()
{
    int quant;

    do
    {
        printf("Indique quantidade de avaliados(1-%d): ", max_estudantes);
        scanf("%d", &quant);

        if (quant > max_estudantes || quant < 1)
        {
            printf("Tas parvo ou que?");
        }
    } while (quant > max_estudantes || quant < 1);

    return quant;
}

void mostrarDados(int v[max_estudantes], int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("Nota do estudante %d = %d\n", i, v[i]);
    }
}

void lerNotas(int v[], int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        printf("Indique a nota do estudante %d : ", i);
        scanf("%d", &v[i]);
    }
}

void alterarNota(int v[], int num)
{
    int notaAlterar;
    int nota;
    printf("Qual é a nota que pretende alterar?: ");
    scanf("%d", &notaAlterar);

    printf("Qual será o valor que pretende inserir: ");
    scanf("%d", &nota);
    v[notaAlterar] = nota;

}

void notasPositivas(int v[], int num) {
    
    int soma;
    float perc_notas;
    for (int i = 0; i < num; i++)
    {
        if(v[i] > 0) {
            printf("A nota %d é positiva\n", num);
            soma += v[i];
        }
        perc_notas = (float)soma / num;
        printf("A percentagem de notas positivas é de: %f\n", perc_notas);
    }
    
}