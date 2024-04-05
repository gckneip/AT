#ifndef PARSER_H
#define PARSER_H

typedef struct node {
  char conteudo;
  int quantosFilhos, capacidade;
  struct node *pai, **filhos;
} Nodo;

typedef struct nodequeue {
  int tamanho;
  struct node ** nodos; 
} Pilha;

Nodo* criaNodo(char conteudo);
Nodo* criaRaiz();
Pilha* criaPilha ();
void pilhaAdiciona(Pilha *pilha, Nodo *nodo); //eventualmente renomear para "pilhaPush"
Nodo* pilhaPop(Pilha *pilha);
void adicionaFilho(Nodo *pai, Nodo *filho);
Nodo* criaArvore(char * entrada);
void desalocaArvore(Nodo* raiz);
#endif
