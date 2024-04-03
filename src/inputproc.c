#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputproc.h"

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

Nodo* criaLista (){
  Nodo* novoNodo = (Nodo*) (malloc(sizeof(Nodo)));
  if (novoNodo == NULL){
    fputs("Nao foi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->proximo=NULL;
  return novoNodo;
}

Nodo* criaNodo (char conteudo){
  Nodo* novoNodo = (Nodo*) (malloc(sizeof(Nodo)));
  if (novoNodo == NULL){
    fputs("Nao foi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->conteudo=conteudo;
  novoNodo->proximo=NULL;
  return novoNodo;
}

Nodo* processaVariaveis (char * entrada){
  int variaveis = 0, i;
  char c;
  Nodo* saida = criaLista();
  Nodo *nodoAnterior, *novoNodo;
  printf("%s\n", entrada);
  for (i = 0; ((c = entrada[i]) != '\0'); i++){
    printf("parsing -> %c\n", entrada[i]);
    if (c >='a' && c <= 'z'){
      for(nodoAnterior = saida; ((nodoAnterior->proximo != NULL) && (nodoAnterior->proximo->conteudo < c)); nodoAnterior = nodoAnterior->proximo);
      if((nodoAnterior->proximo != NULL && nodoAnterior->proximo->conteudo != c) || nodoAnterior->proximo == NULL){
        novoNodo = criaNodo(c);
        novoNodo->proximo = nodoAnterior->proximo;
        nodoAnterior->proximo = novoNodo;
        variaveis++;
      }
    }
  } 
  return saida;
}
