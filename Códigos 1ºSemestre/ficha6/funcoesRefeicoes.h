#ifndef FUNCOESREFEICOES_H_INCLUDED
#define FUNCOESREFEICOES_H_INCLUDED

#include "funcoesAuxiliares.h"
#include "funcoesEstudantes.h"

#define MAX_RESERVAS 50

typedef struct
{
    int codigoReserva;
    int numeroEstudante;
    tipoData dataRefeicao;
    int tipoRefeicao;
} tipoReserva;

int acrescentarReserva(
       tipoReserva vetorReservas[MAX_RESERVAS],
       int reservas,
       tipoEstudante vAlunos[MAX_ESTUDANTES],
       int quantAlunos);
tipoReserva lerDadosReserva(void);


#endif
