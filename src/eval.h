#ifndef EVAL_H
#define EVAL_H

#include "estruturas.h"
unsigned char * geraTabela (Nodo * arvore, int quantasEntradas, char * entradas);
unsigned char percorreArvore(Nodo * raiz, char * variaveis, int quantasEntradas, unsigned char entrada);
int valorBitIndice(int indice, int bit);
unsigned char procuraZero(Nodo * raiz, char * variaveis, int quantasEntradas, unsigned char entrada);
#endif
