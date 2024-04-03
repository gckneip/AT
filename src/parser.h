#ifndef PARSER_H
#define PARSER_H

struct node {
    char conteudo;
    struct node* esquerda;
    struct node* direita;
};

typedef struct node Nodo;

Nodo* criaNodo(char conteudo);
Nodo* criaLista (void);
Nodo* criaLista ();
#endif
