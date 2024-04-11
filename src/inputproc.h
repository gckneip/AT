#ifndef INPUTPROC_H
#define INPUTPROC_H

struct nodo {
    char conteudo;
    char valor;
    struct nodo* proximo;
};

typedef struct nodo Lista;

Lista* processaVariaveis (char * entrada);
Lista* criaListaNodo(char conteudo);
Lista* criaListaRaiz();
#endif
