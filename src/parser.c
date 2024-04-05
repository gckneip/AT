#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#define MAX_PILHA 30 // tive que implementar um limite superior pra (nossa) pilha porque os reallocs estão quebrando completamente o stack :(

int main(int argc, char *argv[]){
  if (argc>1){
    Nodo* arvoreSintaxe = criaArvore(argv[1]);

    printf("Gerou uma arvere \'%c\' com %d filhos na raiz (produtos)\n", arvoreSintaxe->conteudo, arvoreSintaxe->quantosFilhos);
    for(int i = 0; i < arvoreSintaxe->quantosFilhos; i++){
      printf("%c\t", arvoreSintaxe->filhos[i]->conteudo);
    }
    putc('\n', stdout);
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
  novoNodo->conteudo='+';
  novoNodo->filhos=malloc(sizeof(Nodo*));
  return novoNodo;
}

Pilha* criaPilha (){
  Pilha* novaPilha = (Pilha*) (malloc(sizeof(Pilha)));
  novaPilha->tamanho=0;
  novaPilha->nodos=malloc(sizeof(Nodo*)*MAX_PILHA);

  return novaPilha;
}

void pilhaAdiciona(Pilha *pilha, Nodo *nodo){
  if(pilha->tamanho >= MAX_PILHA){
    fputs("stack overflow!", stderr);
    exit(EXIT_FAILURE);
  }
  pilha->nodos[pilha->tamanho]=nodo;
  pilha->tamanho++;
}

Nodo* pilhaPop(Pilha *pilha){
  Nodo *ultimoItem = pilha->nodos[pilha->tamanho - 1];
  if(pilha->tamanho <= 0){
  fputs("stack underflow!\n", stderr);
  exit(EXIT_FAILURE);
  }
  pilha->tamanho--;
  return ultimoItem;
}

void adicionaFilho(Nodo *pai, Nodo *filho){
  /* 
    *
    * ESSA FUNÇÃO ESTÁ CORROMPENDO O STACK E VAZANDO MEMÓRIA SEGUNDO O VALGRDIND
    * o realloc começa a despirocar depois de qualquer resize de tamanho > 4: os 
    * ponteiros começam a desaparecer, e o programa dá segfault. 
    *
    * ... mas fora isso funciona perfeitamente
    *
    */
  if(realloc(pai->filhos, sizeof(Nodo*)*(pai->quantosFilhos + 1))){
    pai->filhos[pai->quantosFilhos]=filho;
    pai->quantosFilhos++;
  }
}

Nodo* criaArvore(char * entrada){
  Nodo *novoNodo, *arvoreSintaxe = criaRaiz();
  Pilha *operadores= criaPilha(), *operandos= criaPilha(), *processados = criaPilha();
  char c;
  int i;

  for (i = 0; ((c = entrada[i]) != '\0'); i++){
    if (c == '!'){
      if (operadores->tamanho > 0 && operadores->nodos[operadores->tamanho-1]->conteudo == '!'){ //trata dulpa negação pro bodinho não infartar (também é uma otimização!!!)
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

    if (c == '*'){
      continue; //vai que...
    }

    if (c == '+'){
      novoNodo = criaNodo('*');
      while(operandos->tamanho){
        adicionaFilho(novoNodo, pilhaPop(operandos));
      }
      pilhaAdiciona(processados, novoNodo);
    }
  }

   novoNodo = criaNodo('*');
   while(operandos->tamanho){
    adicionaFilho(novoNodo, pilhaPop(operandos));
  }
  pilhaAdiciona(processados, novoNodo);

  while(processados->tamanho){
    adicionaFilho(arvoreSintaxe, pilhaPop(processados));
  }

  return arvoreSintaxe;
}
