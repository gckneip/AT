ifeq ($(OS), Windows_NT)
	ARQUIVO=AT.exe
else
	ARQUIVO=AT
endif

$(ARQUIVO): main.o
	gcc main.o 

main.o: tabela.o transicoes.o eval.o parser.o inputproc.o
	gcc -c src/main.c

transicoes.o: 
	gcc -c src/transicoes.c

inputproc.o: 
	gcc -c src/inputproc.c

parser.o: 
	gcc -c src/parser.c

tabela.o:
	gcc -c src/tabela.c

