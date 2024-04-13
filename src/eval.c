#include "eval.h"
#include "estruturas.h"
#include <stdlib.h>


int valorBitIndice(int indice, int bit) { return ((indice & 1 << bit) >> bit); }

unsigned char *geraTabela(Nodo *arvore, int quantasEntradas, char *entradas) {
  int tamanhoVetor = 1 << quantasEntradas;
  unsigned char *tabelaVerdade = calloc((tamanhoVetor),sizeof(unsigned char)); // inicia o vetor de resultados com 2^n

  for (int i = 0; i < tamanhoVetor; i++) {
    tabelaVerdade[i] = percorreArvore(arvore, entradas, quantasEntradas, i);
  }

  return tabelaVerdade;
}

unsigned char percorreArvore(Nodo *raiz, char *variaveis, int quantasEntradas, unsigned char entrada) {
  int i, j;
  char c;
  if (raiz->conteudo == '+') {
    for (i = 0; i < raiz->quantosFilhos; i++) {
      if (procuraZero(raiz->filhos[i], variaveis, quantasEntradas, entrada))
        continue;
      return 1;
    }
  }
  return 0;
}

unsigned char procuraZero(Nodo *raiz, char *variaveis, int quantasEntradas, unsigned char entrada) {
  int i, j;

  for (i = 0; i < raiz->quantosFilhos; i++) {
    if (raiz->filhos[i]->conteudo >= 'a' && raiz->filhos[i]->conteudo <= 'z') {
      for (j = 0; j < quantasEntradas; j++) {
        if (variaveis[j] == raiz->filhos[i]->conteudo) {
          if (valorBitIndice(entrada, quantasEntradas - j - 1) == 0) {
            return 1;
          }
        }
      }
    }
    if (raiz->filhos[i]->conteudo == '!') {
      for (j = 0; j < quantasEntradas; j++) {
        if (variaveis[j] == raiz->filhos[i]->filhos[0]->conteudo) {
          if (valorBitIndice(entrada, quantasEntradas - j - 1) == 1) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}
