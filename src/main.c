#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include "parser.h"
#include "transicoes.h"
#include "inputproc.h"
#include "eval.h"

void percorreArvore(Nodo* raiz);

int main(int argc, char *argv[]){
  if (argc>1){
    int i = 0;
    Nodo* raiz = criaArvore(argv[1]);
    Lista* variaveis = processaVariaveis(argv[1]);
    percorreArvore(raiz);
    
    for (Lista *current = variaveis->proximo; current != NULL; current=current->proximo){
      printf("%c ", current->conteudo);
      i++;
    }
    printf("\n");
    tabelaVerdade(i,raiz,variaveis);
    desalocaArvore(raiz);
  }
  return EXIT_SUCCESS;
  return 0;
}

void percorreArvore(Nodo* raiz){
  int vo, pai, neto;
    for(vo = raiz->quantosFilhos; vo > 0; vo--){
      for(pai = raiz->filhos[vo-1]->quantosFilhos; pai > 0; pai--){
        for(neto = raiz->filhos[vo-1]->filhos[pai-1]->quantosFilhos; neto > 0; neto--){
            printf("%c", raiz->filhos[vo-1]->filhos[pai-1]->filhos[neto-1]->conteudo);
          }                  
        printf("%c", raiz->filhos[vo-1]->filhos[pai-1]->conteudo);         
      }
      printf("%c", raiz->filhos[vo-1]->conteudo);        
    }
  printf("%c\n", raiz->conteudo);
}