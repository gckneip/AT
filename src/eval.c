#include <stdio.h>
#include <stdlib.h>
#include "eval.h"

int main(int argc, char *argv[])
{
  

  return EXIT_SUCCESS;
}

int * geraTabela (Nodo * arvore, int quantasEntradas, Lista * entradas){
  int tamanhoVetor = 1 << quantasEntradas;
  int * tabelaVerdade = calloc(tamanhoVetor, sizeof(unsigned char)); //inicia o vetor de resultados com 2^n elementos, tudo zerado

  return tabelaVerdade;
} 
