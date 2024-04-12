#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  //                     abcde
  char arco[4] = {0};
  unsigned char tabelaVerdade[] = {0, 1, 0, 1, 0, 0, 1, 1};
  char operandos[] = {'a', 'b', 'c'};
  int quantosOperandos = 3, peso, indiceTabela = 0;
  int i, j, k, l = 0;

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
      //printf("%s eh o arco %03b -> %03b\n----------\n",arco , indiceTabela, indiceTabela + (1 << ((quantosOperandos -1) - i)));

      if(tabelaVerdade[indiceTabela] != tabelaVerdade[indiceTabela + (1 << ((quantosOperandos - 1) - i))])
        printf("%s\n", arco);
      l = 0;
      indiceTabela = 0;
    }
  }

  return EXIT_SUCCESS;
}
