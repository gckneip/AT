ifeq ($(OS), Windows_NT)
	ARQUIVO=AT.exe
else
	ARQUIVO=AT
endif

$(ARQUIVO): tabela.o transicoes.o main.o
	gcc main.o tabela.o transicoes.o

main.o: transicoes.o tabela.o
	gcc -c src/main.c

transicoes.o: tabela.o
	gcc -c src/transicoes.c

tabela.o:
	gcc -c src/tabela.c

