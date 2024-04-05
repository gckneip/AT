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
    fputs("Nao fhoi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->conteudo=conteudo;
  novoNodo->filhos=malloc(sizeof(Nodo*));
  novoNodo->quantosFilhos=0;
  return novoNodo;
}

Nodo* criaRaiz (){
  Nodo *novoNodo = (Nodo*) (malloc(sizeof(Nodo)));
  if (novoNodo == NULL){
    fputs("Nao foi possível alocar memoria.", stderr);
    exit(EXIT_FAILURE);
  }
  novoNodo->quantosFilhos=0;
  novoNodo->filhos=malloc(sizeof(Nodo*));
  return novoNodo;
}

Pilha* criaPilha (){
  Pilha* novaPilha = (Pilha*) (malloc(sizeof(Pilha)));
  novaPilha->tamanho=0;
  novaPilha->nodos=malloc(sizeof(Nodo*));

  return novaPilha;
}

void pilhaAdiciona(Pilha *pilha, Nodo *nodo){
  if(realloc(pilha->nodos, sizeof(Nodo*)*(pilha->tamanho+ 1))){
    pilha->nodos[pilha->tamanho]=nodo;
    pilha->tamanho++;
  }
}

Nodo* pilhaPop(Pilha *pilha){
  Nodo *ultimoItem = pilha->nodos[pilha->tamanho];
  if(realloc(pilha->nodos, sizeof(Nodo*)*(pilha->tamanho-1))){
    pilha->tamanho--;
    return ultimoItem;
  }
  fputs("Deu ruim o pop.", stderr);
  exit(EXIT_FAILURE);
}

void adicionaFilho(Nodo *pai, Nodo *filho){
  if(realloc(pai->filhos, sizeof(Nodo*)*(pai->quantosFilhos + 1))){
    pai->filhos[pai->quantosFilhos]=filho;
    pai->quantosFilhos++;
  }
}

Nodo* criaArvore(char * entrada){
  Nodo *arvoreSintaxe = criaRaiz();
  Pilha *operadores, *operandos= criaPilha();
  Nodo *novoNodo, *nodoAnterior;
  char c;
  int i;

  for (i = 0; ((c = entrada[i]) != '\0'); i++){
    if (c == '!'){
      if (operadores->tamanho > 0 && operadores->nodos[operadores->tamanho-1]->conteudo == '!'){ //trata dulpa negação pro bodinho não infartar
        pilhaPop(operadores);
        continue;
      }
      novoNodo = criaNodo(c);
      pilhaAdiciona(operadores, novoNodo);
    }

    if (c >='a' && c <= 'z'){
      novoNodo = criaNodo(c);
      if (operadores->tamanho > 0 && operadores->nodos[operadores->tamanho-1]->conteudo == '!'){
        adicionaFilho(operadores->nodos[operadores->tamanho-1], novoNodo);
        pilhaAdiciona(operandos, pilhaPop(operadores));
        continue;
      }
      pilhaAdiciona(operandos, novoNodo);
    }
  }

  return arvoreSintaxe;
}
