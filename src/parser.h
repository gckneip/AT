#ifndef PARSER_H
#define PARSER_H
#include "estruturas.h"

Nodo *criaNodo(char conteudo);
Nodo *criaRaiz();
Pilha *criaPilha();
void pilhaPush(Pilha *pilha, Nodo *nodo);
Nodo *pilhaPop(Pilha *pilha);
void adicionaFilho(Nodo *pai, Nodo *filho);
Nodo *criaArvore(char *entrada);
void desalocaArvore(Nodo *raiz);
#endif
