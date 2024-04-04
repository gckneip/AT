#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int main(int argc, char *argv[]){
  if (argc>1){
  }
  return EXIT_SUCCESS;
}


Nodo* criaNodo (char conteudo){
  Nodo *novoNodo = (Nodo*) (malloc(sizeof(Nodo)));
  if (novoNodo == NULL){
    fputs("Nao foi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->conteudo=conteudo;
  novoNodo->filhos=NULL;
  return novoNodo;
}

Nodo* criaLista (){
  Nodo *novoNodo = (Nodo*) (malloc(sizeof(Nodo)));
  if (novoNodo == NULL){
    fputs("Nao foi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->quantosFilhos;
  return novoNodo;
}

void adicionaFilho(Nodo *pai, Nodo *filho){
  if(realloc(pai->filhos, sizeof(Nodo)))
}

Nodo* criaArvore(char * entrada){
  Nodo *processado, *arvoreSintaxe, *filaVariaveis, *filaOperadores = criaLista();
  Nodo *nodoAnterior, *novoNodo;
  char c;
  int i;

  for (i = 0; ((c = entrada[i]) != '\0'); i++){
    if (c >='a' && c <= 'z'){
      for(nodoAnterior = filaVariaveis;nodoAnterior->filhos != NULL; nodoAnterior = nodoAnterior->filhos);
    }
  }

  return arvoreSintaxe;
}
