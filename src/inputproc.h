#ifndef INPUTPROC_H
#define INPUTPROC_H
#include "estruturas.h"

int processaVariaveis (char * entrada, char ** saidaLista);
Lista * criaItem(char caractere);
void desalocaLista (Lista * entrada);
#endif
