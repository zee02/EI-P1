#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoesAuxiliares.h"
#include "funcoesEstudantes.h"
#include "funcoesDeFicheiros.h"
#include "funcoesRefeicoes.h"

#define NOTA_POSITIVA 9.5


char menu(int quantEstudantes, int avaliados, float percPositivas);
void contas(tipoEstudante vAlunos[MAX_ESTUDANTES], int quantEstudantes, float *percPos, int *quantidadeComNota);


int main() {
    int totalEstudantes, quantAvaliados, totalReservas;
    float percentagemPos;
    char opcao;
    tipoEstudante vetorEstudantes[MAX_ESTUDANTES];
    tipoReserva vetorReservas[MAX_RESERVAS];

    totalEstudantes=0;
    totalReservas=0;
    quantAvaliados=0;
    percentagemPos = 0.0;

    /*
    totalEstudantes = lerQuantidadeAvaliados();

    for (i=0; i<totalEstudantes; i++)
    {
        vetorEstudantes[i] = lerDadosEstudante();
    }*/

	do {
        contas(vetorEstudantes,totalEstudantes,&percentagemPos,&quantAvaliados);
		opcao = menu(totalEstudantes, quantAvaliados, percentagemPos);
		switch(opcao) {
		case 'A':
			totalEstudantes = acrescentaEstudante(vetorEstudantes,totalEstudantes);
			break;
		case 'I':
            lerNotas(vetorEstudantes, totalEstudantes);
			break;
		case 'M':
			mostrarDados(vetorEstudantes, totalEstudantes);
			break;
		case 'G':
		    printf("Gravar para ficheiro.\n");
			gravaFicheiroBinario(vetorEstudantes,totalEstudantes);
			gravaFicheiroTexto(vetorEstudantes,totalEstudantes);
			printf(" ----\n|TODO| -- Gravar reservas\n ----");
			break;
		case 'L':
			printf("Ler de ficheiro.\n");
			totalEstudantes = leFicheiroBinario(vetorEstudantes);
			printf(" ----\n|TODO| -- Ler reservas\n ----");
			break;
        case '1':
            acrescentarReserva(vetorReservas,totalReservas,vetorEstudantes,totalEstudantes);
            break;
    	case '2':
            printf(" ----\n|TODO| -- Eliminar Researva\n ----");
            break;
        case '3':
            printf(" ----\n|TODO| -- Mostrar Researvas\n ----");
            break;
		}
	} while (opcao != 'F');

    return 0;
}

char menu(int quantEstudantes, int avaliados, float percPositivas) {
    char opcao;

    do {
        printf("\n\n\tMenu Principal\n\nEstudantes Inseridos: %2d\n",quantEstudantes);
		printf("Estudantes Avaliados: %2d\t\t\t Positivas(%%): %6.2f\n", avaliados, percPositivas);
        printf("\n\nA - Acrescenta estudante\nI - Introducao Notas de Estudante \n");
        printf("M - Mostrar Dados\nG - Gravar dados em ficheiros\n");
        printf("L - Ler dados de ficheiro \n");

        printf("\n\t 1- Inserir Reserva ");
		printf("\n\t 2- Eliminar Reserva");
		printf("\n\t 3- Mostrar Dados Reservas");

        printf("F - Fim\n\n\tOpcao--> ");
        scanf("%c", &opcao);
        opcao = toupper(opcao);
        limpaBufferStdin();
    } while (opcao!='A' && opcao!='I' && opcao!='M' && opcao!='G'
             && opcao!='L' && opcao!='F' && opcao!='1' && opcao!='2'
             && opcao!='3');
    return opcao;
}

void contas(tipoEstudante vAlunos[MAX_ESTUDANTES],
            int quantEstudantes,
            float *percPos,
            int *quantidadeComNota){
    int i, contaPositivas;
    (*quantidadeComNota) = 0;
    contaPositivas = 0;

    for (i=0; i< quantEstudantes; i++) {
        if (vAlunos[i].nota != -1) {
            (*quantidadeComNota)++;

            if (vAlunos[i].nota >= NOTA_POSITIVA){
                contaPositivas++;
            }
        }
    }

    if(quantEstudantes==0){
        (*percPos) = 0.0;
    }else{
        (*percPos) = contaPositivas * 100.0 / quantEstudantes;
    }
}







