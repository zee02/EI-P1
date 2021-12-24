#ifndef FUNCOESDEFICHEIROS_H_INCLUDED
#define FUNCOESDEFICHEIROS_H_INCLUDED

#include "funcoesEstudantes.h"

void gravaFicheiroBinario(
            tipoEstudante vEstudantes[MAX_ESTUDANTES],
            int numEstudantes);
int leFicheiroBinario(
    tipoEstudante vEstudantes[MAX_ESTUDANTES]);
void gravaFicheiroTexto(tipoEstudante vEstudantes[MAX_ESTUDANTES],
                        int numEstudantes);


#endif
