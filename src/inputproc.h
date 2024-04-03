#ifndef INPUTPROC_H
#define INPUTPROC_H

struct nodo {
    char conteudo;
    struct nodo* proximo;
};

typedef struct nodo Nodo;

Nodo* processaVariaveis (char * entrada);
Nodo* criaNodo(char conteudo);
Nodo* criaLista (void);
Nodo* criaLista ();
#endif
