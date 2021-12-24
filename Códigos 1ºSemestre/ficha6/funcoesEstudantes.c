#include <stdio.h>
#include <stdlib.h>

#include "funcoesEstudantes.h"
#include "funcoesAuxiliares.h"


int lerQuantidadeAvaliados(void) {
    int numAvaliados;
    numAvaliados = lerInteiro("Indique Estudantes Avaliados",0,MAX_ESTUDANTES);
    return numAvaliados;

}

tipoEstudante lerDadosEstudante() {
    tipoEstudante dados;

    dados.numero = lerInteiro("Numero do estudante",NUMESTUDANTE_MIN,NUMESTUDANTE_MAX);

    lerString("Nome do estudante: ", dados.nome, MAX_STRING);

    dados.nota = -1;
    dados.totalReservasRefeicoes = 0;

    return dados;
}

int acrescentaEstudante(tipoEstudante vetorEstudantes[MAX_ESTUDANTES],
                        int quantidadeEstudantes){
    float nota;
    tipoData data;
    int posicao;
    tipoEstudante infoEstudante;

    printf("\n ACESCENTA ESTUDANTE\n");

    if( quantidadeEstudantes == MAX_ESTUDANTES ){ // vetor cheio
        printf("Nao cabem mais alunos no sistema!!!");
    }else{
        infoEstudante = lerDadosEstudante();

        posicao = procuraEstudante(vetorEstudantes,
                                   quantidadeEstudantes,
                                   infoEstudante.numero);
        if (posicao == -1){
            vetorEstudantes[quantidadeEstudantes] = infoEstudante;
            nota =  lerFloat(" Nota ", MIN_NOTA, MAX_NOTA);
            vetorEstudantes[quantidadeEstudantes].nota = nota;
            data = lerData();
            vetorEstudantes[quantidadeEstudantes].dataAvaliacao = data;
            quantidadeEstudantes++;
        }else{
            printf("Esse numero de estudante ja existe.\n");
        }
    }

    return quantidadeEstudantes;
}

int procuraEstudante(tipoEstudante vetorEstudantes[MAX_ESTUDANTES],
                        int quantidadeEstudantes, int numero){
    int i;
    int posicao=-1;
    for(i=0; i<quantidadeEstudantes; i++){
        if (vetorEstudantes[i].numero == numero) {
            posicao = i;
            i = quantidadeEstudantes;
        }
    }
    return posicao;
}

void mostrarDados(tipoEstudante vAlunos[MAX_ESTUDANTES], int quantEstudantes) {
    int i;

    if (quantEstudantes == 0) {
        printf("\n\nAinda nao existem estudantes inscritos!\n\n");
    } else {
        printf("numero      nome            NumRefs  nota Final    Data");
        for (i=0; i<quantEstudantes; i++) {
            printf("\n%-12d%-16s", vAlunos[i].numero, vAlunos[i].nome);
            printf(" %-9d", vAlunos[i].totalReservasRefeicoes);
            if (vAlunos[i].nota == -1) {
                printf("  Sem nota ");
            } else {
                printf("%10.2f ", vAlunos[i].nota);
                printf("   %2d-%2d-%4d", vAlunos[i].dataAvaliacao.dia,
                       vAlunos[i].dataAvaliacao.mes,
                       vAlunos[i].dataAvaliacao.ano);
            }
        }//for
    }
}

void lerNotas(tipoEstudante vAlunos[MAX_ESTUDANTES], int numAvaliados) {
    int aluno;
    tipoData data;

    if (numAvaliados == 0) {
        printf("\n Nao existem estudantes avaliados!!");
    }
    else
    {
        printf("\n Insira as notas (0-20) \n");
        for (aluno=0; aluno<numAvaliados; aluno++)
        {
            do
            {
                printf (" %d %s Nota:", vAlunos[aluno].numero, vAlunos[aluno].nome);
                scanf ("%f", &(vAlunos[aluno].nota) );
                printf("\n Data da Avaliacao: ");
                data = lerData();
                vAlunos[aluno].dataAvaliacao = data;
            }
            while (vAlunos[aluno].nota<0 || vAlunos[aluno].nota>20);
        }
    }
}




