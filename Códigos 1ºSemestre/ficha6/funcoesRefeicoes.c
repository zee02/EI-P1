#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoesRefeicoes.h"
#include "funcoesEstudantes.h"


int acrescentarReserva(
       tipoReserva vetorReservas[MAX_RESERVAS],
       int quantReservas,
       tipoEstudante vAlunos[MAX_ESTUDANTES],
       int quantEstudantes)
{
    tipoReserva dados;
    int numeroEstudante, posicao;

    if (quantEstudantes == 0)
    {
        printf("Ainda nao existem estudantes");
    }
    else
    {
        if (quantReservas == MAX_RESERVAS)
        {
            printf("Impossivel acrescentar novos elementos - Vetor de reservas ja esta completo!!!");
        }
        else
        {
            numeroEstudante = lerInteiro("\n Numero Estudante: ",NUMESTUDANTE_MIN, NUMESTUDANTE_MAX);
            posicao = procuraEstudante(vAlunos, quantEstudantes, numeroEstudante);

            if (posicao == -1)
            {
                printf("Estudante com numero %d nao existe!\n", numeroEstudante);
            }
            else
            {
                dados = lerDadosReserva();
                dados.numeroEstudante = numeroEstudante;

                if (quantReservas==0){
                    dados.codigoReserva = 1;
                }
                else{
                    dados.codigoReserva = vetorReservas[quantReservas-1].codigoReserva+1;
                }

                vetorReservas[quantReservas] = dados;

                //LogReserva(vetorReservas[quantReservas], 1);
                printf(" ----\n|TODO| -- Fazer Logging de que foi criada uma reserva\n ----");

				// atualiza total de quantReservas do estudante
                vAlunos[posicao].totalReservasRefeicoes++;
                printf("\n Estudante %d ja efetuou %d reserva(s)", numeroEstudante, vAlunos[posicao].totalReservasRefeicoes);

                quantReservas++;
            }
        }
    }
    return quantReservas;
}


tipoReserva lerDadosReserva(void)
{
    tipoReserva dadosReserva;

    printf("\n\nINSERIR DADOS DA RESERVA\n");
    printf("\n\nData da reserva\n");

    dadosReserva.dataRefeicao = lerData();

    dadosReserva.tipoRefeicao = lerInteiro("Tipo de refeicao (1 - Almoco   2 - Jantar): ",1, 2);

    return dadosReserva;
}










