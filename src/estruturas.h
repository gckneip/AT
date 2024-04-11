#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct node {
  char conteudo;
  int quantosFilhos, capacidade;
  struct node **filhos;
} Nodo;

typedef struct nodequeue {
  int tamanho;
  struct node ** nodos; 
} Pilha;

#endif
