#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int main(int argc, char *argv[]){
  if (argc>1){
    Nodo *variaveis = processaVariaveis(argv[1]);
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
  novoNodo->direita=NULL;
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

