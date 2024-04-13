ifeq ($(OS), Windows_NT)
	ARQUIVO=AT.exe
else
	ARQUIVO=AT
endif

CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Isrc

$(ARQUIVO): transicoes.o eval.o parser.o main.o inputproc.o
	$(CC) $^ -o $@ $(LIBS)

main.o: src/main.c
	$(CC) $(CFLAGS) -c $<  -o $@

transicoes.o: src/transicoes.c
	$(CC) $(CFLAGS) -c $< -o $@

parser.o: src/parser.c
	$(CC) $(CFLAGS) -c $< -o $@

eval.o:  src/eval.c
	$(CC) $(CFLAGS) -c $< -o $@

inputproc.o: src/inputproc.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ARQUIVO) *.o
