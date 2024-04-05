#ifndef PARSER_H
#define PARSER_H

typedef struct node {
  char conteudo;
  int quantosFilhos;
  struct node **filhos;
} Nodo;

typedef struct nodequeue {
  int tamanho;
  struct node ** nodos; 
} Pilha;

Nodo* criaNodo(char conteudo);
Nodo* criaRaiz();
void adicionaFilho(Nodo *pai, Nodo *filho);
Nodo* criaArvore(char * entrada);
#endif
