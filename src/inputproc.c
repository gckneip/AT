#include "inputproc.h"
#include <stdio.h>
#include <stdlib.h>

Lista *criaItem(char caractere) {
  Lista *saida = (Lista *)malloc(sizeof(Lista));

  if(saida == NULL){
    fputs("Nao foi possivel alocar memoria para a um dos itens da lista de operandos", stderr);
    exit(EXIT_FAILURE);
  }

  saida->conteudo = caractere;
  saida->proximo = NULL;
  return saida;
}

int processaVariaveis(char *entrada, char ** saidaLista) {
  char *saida;
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

  saida= (char*) malloc(variaveis * sizeof(char));
  if(saida == NULL){
    fputs("Nao foi possivel alocar memoria para a tabela verdade", stderr);
    exit(EXIT_FAILURE);
  }
  i = 0;
  for (itemAnterior = lista; itemAnterior->proximo != NULL;itemAnterior = itemAnterior->proximo) {
    saida[i] = itemAnterior->proximo->conteudo;
    i++;
  }
  desalocaLista(lista);
  *saidaLista = saida;
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
