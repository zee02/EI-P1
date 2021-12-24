#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesDeFicheiros.h"
#include "funcoesEstudantes.h"


void gravaFicheiroBinario(
		tipoEstudante vEstudante[MAX_ESTUDANTES],
		int numEstudantes)
{
	FILE *ficheiro;
	int quantEscritaParaFicheiro;
	ficheiro=fopen("dadosEstudantes.dat","wb");
	if (ficheiro == NULL) {
		printf("Erro abrir ficheiro");
	}else{
		quantEscritaParaFicheiro = fwrite(&numEstudantes,sizeof(int),1,ficheiro);
        if (quantEscritaParaFicheiro != 1) {
            printf("Erro ao escrever a quantidade de estudantes");
        }
		quantEscritaParaFicheiro = fwrite(vEstudante,sizeof(tipoEstudante),numEstudantes,ficheiro);
        if (quantEscritaParaFicheiro != numEstudantes) {
            printf("Erro ao escrever dados de estudntes");
        }
		fclose(ficheiro);
    }
}

int leFicheiroBinario(
		tipoEstudante vEstudante[MAX_ESTUDANTES])
{
    FILE *ficheiro;
    int numElementos;
    int quantLeituraDeFicheiro;
    ficheiro=fopen("dadosEstudantes.dat","rb");
    if (ficheiro == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
        quantLeituraDeFicheiro = fread(&numElementos,sizeof(int),1,ficheiro);
        if (quantLeituraDeFicheiro != 1) {
            printf("Erro ao obter informacao da quantidade de estudantes");
        }
        quantLeituraDeFicheiro = fread(vEstudante,sizeof(tipoEstudante),numElementos,ficheiro);
        if (quantLeituraDeFicheiro != numElementos) {
            printf("Erro ao obter informacao dos estudantes");
        }
        fclose(ficheiro);
    }
    return numElementos;
}



void gravaFicheiroTexto(tipoEstudante vEstudantes[MAX_ESTUDANTES],
                        int numEstudantes) {
    FILE *fich;
    int i;
    fich = fopen("dadosEstudantes.txt","w");
    if (fich == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
        fprintf(fich,"%d\n\n", numEstudantes);
        for (i=0; i<numEstudantes; i++) {
            fprintf(fich,"%d\n",vEstudantes[i].numero);
            fprintf(fich,"%s\n",vEstudantes[i].nome);
            fprintf(fich,"%f\n",vEstudantes[i].nota);
            fprintf(fich,"%02d/%02d/%04d\n\n",
                    vEstudantes[i].dataAvaliacao.dia,
                    vEstudantes[i].dataAvaliacao.mes,
                    vEstudantes[i].dataAvaliacao.ano);
        }
        fclose(fich);
    }
}


