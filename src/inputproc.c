#include "inputproc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc > 1) {

    char *vetorVariaveis = (char*) malloc(sizeof(char));
    int quantasVariaveis = processaVariaveis(argv[1], vetorVariaveis);
    
    printf("chegou aqui e travou? anyway sao %d variaveis\n", quantasVariaveis);

    for (int i = 0; i < quantasVariaveis; i++) {
      printf("%d -> %c\n",i, vetorVariaveis[i]);
    }
  }

  return EXIT_SUCCESS;
}

Lista *criaItem(char caractere) {
  Lista *saida = (Lista *)malloc(sizeof(Lista));
  saida->conteudo = caractere;
  saida->proximo = NULL;
  return saida;
}

int processaVariaveis(char *entrada, char *saida) {
  Lista *lista = criaItem('\0');
  int variaveis = 0, i;
  char c;
  Lista *itemAnterior, *novoItem;
  for (i = 0; ((c = entrada[i]) != '\0'); i++) {
    if (c >= 'a' && c <= 'z') {
      for (itemAnterior = lista; ((itemAnterior->proximo != NULL) &&
                                  (itemAnterior->proximo->conteudo < c));
           itemAnterior = itemAnterior->proximo);
      if ((itemAnterior->proximo != NULL &&
           itemAnterior->proximo->conteudo != c) ||
          itemAnterior->proximo == NULL) {
        novoItem = criaItem(c);
        novoItem->proximo = itemAnterior->proximo;
        itemAnterior->proximo = novoItem;
        variaveis++;
      }
    }
  }

  saida = (char*) realloc(saida, sizeof(char)*variaveis);
  i = 0;
  for (itemAnterior = lista; itemAnterior->proximo != NULL;itemAnterior = itemAnterior->proximo) {
    saida[i] = itemAnterior->proximo->conteudo;
    i++;
  }
  desalocaLista(lista);
  return variaveis;
}

void desalocaLista(Lista *entrada) {
  Lista *itemAnterior, *liberado;
  for (itemAnterior = entrada;
       itemAnterior != NULL && (itemAnterior->proximo != NULL);
       free(liberado)) {
    liberado = itemAnterior;
    itemAnterior = itemAnterior->proximo;
  }
  free(itemAnterior);
}
