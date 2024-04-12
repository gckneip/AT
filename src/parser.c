#include <stdlib.h>
#include <stdio.h>
#include "parser.h"

#define MAX_PILHA 30 // achei solucao pra alocar a pilha dinamicamente, me avisem se for necessario, não quero quebrar o que ja tá bombando
#define INI_ARESTAS 5

int main(int argc, char *argv[])
{
  if(argc>1){
    Nodo * arvore = criaArvore(argv[1]);
    desalocaArvore(arvore);
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
  novoNodo->filhos=malloc(sizeof(* novoNodo)*INI_ARESTAS);
  novoNodo->quantosFilhos=0;
  novoNodo->capacidade=INI_ARESTAS;
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
  novoNodo->filhos=malloc(sizeof(* novoNodo)*INI_ARESTAS);
  novoNodo->capacidade=INI_ARESTAS;
  return novoNodo;
}

Pilha* criaPilha (){
  Pilha* novaPilha = (Pilha*) (malloc(sizeof(Pilha)));
  novaPilha->tamanho=0;
  novaPilha->nodos=malloc(sizeof(* novaPilha)*MAX_PILHA);

  return novaPilha;
}

void pilhaAdiciona(Pilha *pilha, Nodo *nodo){
  if(pilha->tamanho >= MAX_PILHA){
    fputs("Stack overflow!", stderr);
    exit(EXIT_FAILURE);
  }
  pilha->nodos[pilha->tamanho]=nodo;
  pilha->tamanho++;
}

Nodo* pilhaPop(Pilha *pilha){
  Nodo *ultimoItem = pilha->nodos[pilha->tamanho - 1];
  if(pilha->tamanho <= 0){
  fputs("Stack underflow!\n", stderr);
  exit(EXIT_FAILURE);
  }
  pilha->tamanho--;
  return ultimoItem;
}

void adicionaFilho(Nodo *pai, Nodo *filho){
  Nodo **novoPonteiro = pai->filhos;
  if (pai->quantosFilhos >= pai->capacidade){
    pai->capacidade *= 2;
    if((novoPonteiro = (Nodo**) realloc(pai->filhos, (sizeof(Nodo *)) * (pai->capacidade))) == NULL){
      fputs("Erro ao realocar vetor de arestas.", stderr);
      exit(EXIT_FAILURE);
    }
  }
  pai->filhos=novoPonteiro;
  pai->filhos[pai->quantosFilhos]=filho;
  pai->quantosFilhos++;
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
  if (operandos->tamanho){
   novoNodo = criaNodo('*');
   while(operandos->tamanho){
    adicionaFilho(novoNodo, pilhaPop(operandos));
  }
  pilhaAdiciona(processados, novoNodo);

  }

  while(processados->tamanho){
    adicionaFilho(arvoreSintaxe, pilhaPop(processados));
  }

  free(operandos->nodos);
  free(operadores->nodos);
  free(processados->nodos);
  free(operandos);
  free(operadores);
  free(processados);
  return arvoreSintaxe;
}

void desalocaArvore(Nodo* raiz){
  int p, vn, v;
  if(raiz->quantosFilhos > 0){
    for(p = raiz->quantosFilhos; p > 0; p--){
      for(vn = raiz->filhos[p-1]->quantosFilhos; vn > 0; vn--){
        for(v = raiz->filhos[p-1]->filhos[vn-1]->quantosFilhos; v > 0; v--){
          if(raiz->filhos[p-1]->filhos[vn-1]->filhos[v-1]->filhos != NULL){
            free(raiz->filhos[p-1]->filhos[vn-1]->filhos[v-1]->filhos);
          }
          free(raiz->filhos[p-1]->filhos[vn-1]->filhos[v-1]);
        }
        if(raiz->filhos[p-1]->filhos[vn-1]->filhos != NULL){
          free(raiz->filhos[p-1]->filhos[vn-1]->filhos);
        }
        free(raiz->filhos[p-1]->filhos[vn-1]);
      }
    if(raiz->filhos[p-1]->filhos != NULL){
      free(raiz->filhos[p-1]->filhos);
    }
    free(raiz->filhos[p-1]);
    }
  }
  free(raiz->filhos);
  free(raiz);
}
