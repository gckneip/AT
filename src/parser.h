#ifndef PARSER_H
#define PARSER_H

struct node {
    char conteudo;
    int quantosFilhos;
    struct node **filhos;
};

typedef struct node Nodo;

Nodo* criaNodo(char conteudo);
Nodo* criaArvore ();
void adicionaFilho(Nodo *pai, Nodo *filho);
Nodo* criaArvore(char * entrada);
#endif
