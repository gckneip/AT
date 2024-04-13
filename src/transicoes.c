#include "transicoes.h"
#include <stdlib.h>
#include <stdio.h>

void imprimeArcos (unsigned char * tabelaVerdade, char * operandos, int quantosOperandos){

  int peso, i, j, k, l = 0;
  int indiceTabela = 0;
  
  char *arco = calloc(sizeof(char), quantosOperandos);

  for (i = 0; i < quantosOperandos; i++) {
    for (j = 0; j < (1 << (quantosOperandos - 1)); j++) {
      for (k = quantosOperandos-1; k >= 0; k--) {
        peso = (quantosOperandos - 1) - k;
        if (k != i) {
          indiceTabela += ((j & 1 << l) >> l) * (1 << peso); //faz o l
          arco[k] = '0' + ((j & 1 << l) >> l);
          l++;
          continue;
        }
        arco[k]=operandos[i];
      }
      if(tabelaVerdade[indiceTabela] != tabelaVerdade[indiceTabela + (1 << ((quantosOperandos - 1) - i))])
        printf("%s\n", arco);
      l = 0;
      indiceTabela = 0;
    }
  }

  free(arco);
}
