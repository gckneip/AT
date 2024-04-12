#include <stdio.h>
#include <stdlib.h>
#include "eval.h"

int main(int argc, char *argv[])
{
  

  return EXIT_SUCCESS;
}

unsigned char * geraTabela (Nodo * arvore, int quantasEntradas, Lista * entradas){
  int tamanhoVetor = 1 << quantasEntradas;
  unsigned char * tabelaVerdade = calloc((1 << quantasEntradas), sizeof(unsigned char)); //inicia o vetor de resultados com 2^n elementos, tudo zerado

  return tabelaVerdade;
} 
