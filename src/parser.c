#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int main(int argc, char *argv[]){
  if (argc>1){
    Nodo* arvoreSintaxe = criaArvore(argv[1]);

    printf("Gerou uma arvere \'%c\' com %d filhos na raiz (produtos), o que ja eh um começo promissor! >)\n", arvoreSintaxe->conteudo, arvoreSintaxe->quantosFilhos);
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
  novaPilha->nodos=malloc(sizeof(Nodo*));

  return novaPilha;
}

void pilhaAdiciona(Pilha *pilha, Nodo *nodo){
  puts("realloc do pilhaAdiciona");
  if(realloc(pilha->nodos, sizeof(Nodo*)*(pilha->tamanho+ 1))){
    pilha->nodos[pilha->tamanho]=nodo;
    pilha->tamanho++;
  }
}

Nodo* pilhaPop(Pilha *pilha){
  Nodo *ultimoItem = (Nodo *) malloc(sizeof(Nodo*));
  ultimoItem = pilha->nodos[pilha->tamanho - 1];
  printf("ponteiro do item removido da pilha de tamanho %d eh -> %p\n",pilha->tamanho, ultimoItem);
  puts("realloc do pilhaPop");
  if(realloc(pilha->nodos, sizeof(Nodo*)*(pilha->tamanho))){
    pilha->tamanho--;
    return ultimoItem;
  }
  fputs("Deu ruim o pop.\n", stderr);
  exit(EXIT_FAILURE);
}

void adicionaFilho(Nodo *pai, Nodo *filho){
  if(realloc(pai->filhos, sizeof(Nodo*)*(pai->quantosFilhos + 1))){
    pai->filhos[pai->quantosFilhos]=filho;
    //printf("foi adicionado o filho com sucesso o filho %c", pai->filhos[pai->quantosFilhos]->conteudo);
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
