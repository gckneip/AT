#include "estruturas.h"
#include "eval.h"
#include "inputproc.h"
#include "parser.h"
#include "transicoes.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    char *variaveis;
    int quantasEntradas = processaVariaveis(argv[1], &variaveis);
    Nodo *arvore = criaArvore(argv[1]);
    unsigned char *tabelaVerdade = geraTabela(arvore, quantasEntradas, variaveis);
    
    imprimeArcos(tabelaVerdade, variaveis, quantasEntradas);

    desalocaArvore(arvore);
    free(variaveis);
    free(tabelaVerdade);
  }
  return EXIT_SUCCESS;

  return 0;
}
