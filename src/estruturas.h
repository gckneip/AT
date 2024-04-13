#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct node {
  char conteudo;
  int quantosFilhos, capacidade;
  struct node **filhos;
} Nodo;

typedef struct nodequeue {
  int tamanho;
  int capacidade;
  struct node ** nodos; 
} Pilha;

typedef struct list{
  char conteudo;
  struct list *proximo;
} Lista;

#endif
