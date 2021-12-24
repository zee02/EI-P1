#ifndef FUNCOESESTUDANTES_H_INCLUDED
#define FUNCOESESTUDANTES_H_INCLUDED

#include "funcoesAuxiliares.h"

#define MAX_ESTUDANTES 100
#define MIN_NOTA 0.00
#define MAX_NOTA 20.00

#define NUMESTUDANTE_MIN 100000
#define NUMESTUDANTE_MAX 999999

typedef struct {
    int numero;
    char nome[MAX_STRING];
    float nota;
    tipoData dataAvaliacao;
    int totalReservasRefeicoes;
} tipoEstudante;

tipoEstudante lerDadosEstudante();
int lerQuantidadeAvaliados(void);
void mostrarDados(tipoEstudante vAlunos[MAX_ESTUDANTES],int quantEstudantes);
void lerNotas(tipoEstudante vAlunos[MAX_ESTUDANTES], int numAvaliados);
int acrescentaEstudante(tipoEstudante vetorEstudantes[MAX_ESTUDANTES],int quantidadeEstudantes);
int procuraEstudante(tipoEstudante vetorEstudantes[MAX_ESTUDANTES], int quantidadeEstudantes, int numero);

#endif
