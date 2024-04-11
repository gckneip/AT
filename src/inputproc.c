#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputproc.h"
/*
int main(int argc, char *argv[]){
  if (argc>1){
    Nodo * variaveis = processaVariaveis(argv[1]);
    int i;

    for (Nodo *current = variaveis->proximo; current != NULL; current=current->proximo){
      printf("%c ", current->conteudo);
      i++;
    }
  }
  return EXIT_SUCCESS;
}
*/

Lista* criaListaRaiz (){
  Lista* novoNodo = (Lista*) (malloc(sizeof(Lista)));
  if (novoNodo == NULL){
    fputs("Nao foi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->proximo=NULL;
  return novoNodo;
}

Lista* criaListaNodo (char conteudo){
  Lista* novoNodo = (Lista*) (malloc(sizeof(Lista)));
  if (novoNodo == NULL){
    fputs("Nao foi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->conteudo=conteudo;
  novoNodo->proximo=NULL;
  return novoNodo;
}

Lista* processaVariaveis (char * entrada){
  int variaveis = 0, i;
  char c;
  Lista* saida = criaListaRaiz();
  Lista *nodoAnterior, *novoNodo;
  for (i = 0; ((c = entrada[i]) != '\0'); i++){
    if (c >='a' && c <= 'z'){
      for(nodoAnterior = saida; ((nodoAnterior->proximo != NULL) && (nodoAnterior->proximo->conteudo < c)); nodoAnterior = nodoAnterior->proximo);
      if((nodoAnterior->proximo != NULL && nodoAnterior->proximo->conteudo != c) || nodoAnterior->proximo == NULL){
        novoNodo = criaListaNodo(c);
        novoNodo->proximo = nodoAnterior->proximo;
        nodoAnterior->proximo = novoNodo;
        variaveis++;
      }
    }
  } 
  return saida;
}