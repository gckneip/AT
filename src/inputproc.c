#include <stdlib.h>
#include "inputproc.h"

Lista * criaItem(char caractere){
  Lista *saida = (Lista *)malloc(sizeof(Lista));
  saida->conteudo=caractere;
  saida->proximo=NULL;
  return saida;
}

int processaVariaveis (char * entrada, Lista * saida){
  int variaveis = 0, i;
  char c;
  Lista *itemAnterior, *novoItem;
  for (i = 0; ((c = entrada[i]) != '\0'); i++){
    if (c >='a' && c <= 'z'){
      for(itemAnterior = saida; ((itemAnterior->proximo != NULL) && (itemAnterior->proximo->conteudo < c)); itemAnterior = itemAnterior->proximo);
      if((itemAnterior->proximo != NULL && itemAnterior->proximo->conteudo != c) || itemAnterior->proximo == NULL){
        novoItem = criaItem(c);
        novoItem->proximo = itemAnterior->proximo;
        itemAnterior->proximo = novoItem;
        variaveis++;
      }
    }
  }
  return variaveis;
}

void desalocaLista (Lista * entrada){
  Lista *itemAnterior, *liberado;
  for(itemAnterior = entrada; itemAnterior!=NULL && (itemAnterior->proximo != NULL); free(liberado)){
    liberado = itemAnterior;
    itemAnterior = itemAnterior->proximo;
  }
  free(itemAnterior);
}
