#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include "parser.h"
#include "inputproc.h"



char calculaArvore(Nodo* raiz, Lista* variaveis){
    int vo, pai, neto;

    for(vo = raiz->quantosFilhos; vo > 0; vo--){
      for(pai = raiz->filhos[vo-1]->quantosFilhos; pai > 0; pai--){//vai testar se algum dos filhos é 0, e se for, vai ser igual a 0
        for(neto = raiz->filhos[vo-1]->filhos[pai-1]->quantosFilhos; neto > 0; neto--){//vai entrar nesse loop se for complemento
            if(raiz->filhos[vo-1]->filhos[pai-1]->filhos[neto-1]->conteudo == '0'){
                raiz->filhos[vo-1]->filhos[pai-1]->filhos[neto-1]->conteudo = '1';
            } else if(raiz->filhos[vo-1]->filhos[pai-1]->filhos[neto-1]->conteudo == '1'){
                raiz->filhos[vo-1]->filhos[pai-1]->filhos[neto-1]->conteudo = '0';
            }
        }
        if(raiz->filhos[vo-1]->filhos[pai-1]->conteudo == '0'){
            raiz->filhos[vo-1]->conteudo = '0';
            //Dá pra dar exit aqui mas n sei como faz :)
        }else if (raiz->filhos[vo-1]->filhos[pai-1]->conteudo != '0'){
            raiz->filhos[vo-1]->conteudo = '1';
        }
      }
      if(raiz->filhos[vo-1]->conteudo == '1'){
        raiz->conteudo = '1';
        //Aqui também dá pra sair do loop mas eu ainda n sei como faz :)
      } else if(raiz->filhos[vo-1]-> conteudo != '1'){
        raiz->conteudo = '0';
      }
    }
    return raiz->conteudo;
}

void tabelaVerdade(int quantidade, Nodo* raiz, Lista* variaveis){
    int i;
    int j;
    char** vetorDeString = (char**) malloc(sizeof(char*) * (pow(2,quantidade)));
    
    for(int i = 0; i < pow(2,quantidade); i++){
      vetorDeString[i] = (char*) malloc(quantidade * sizeof(char));
    }
    
    for(i = 0; i < pow(2,quantidade); i++){
      for(j = 0; j < quantidade; j++){
        vetorDeString[i][j] = (char) ((i >> (quantidade - j - 1) & 1) + 48); //Faz uma operação de shift right e soma 48 para transformar em 0 ou 1 
        printf("%c", vetorDeString[i][j]);
      }

      j = 0; //usar o J para iterar na Lista
      for (Lista *current = variaveis->proximo; current != NULL; current=current->proximo){ //Passando os valores das linhas da tabela para a Lista
        current->valor = vetorDeString[i][j];
        j++;
      }
      /* Descomentar para testar se os valores estão corretamente dispostos na lista
       j = 0; //usar o J para iterar na Lista
      for (Lista *current = variaveis->proximo; current != NULL; current=current->proximo){ //Passando os valores das linhas da tabela para a Lista
        printf("%c = ---%c---", current->conteudo, current->valor);
        j++;
      }
      */
      printf("\n");
      //printf("%c", calculaArvore(raiz, variaveis));
    }

    for (int i = 0; i < pow(2,quantidade); i++) {
      free(vetorDeString[i]);
    }
    free(vetorDeString);
}

