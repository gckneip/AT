ifeq ($(OS), Windows_NT)
	ARQUIVO=sexo.exe
else
	ARQUIVO=sexo
endif

CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Isrc

LIBS += -lm

$(ARQUIVO): transicoes.o eval.o parser.o main.o inputproc.o
	$(CC) $^ -o $@ $(LIBS)

main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -lm -o $@

transicoes.o: src/transicoes.c
	$(CC) $(CFLAGS) -c $< -o $@

parser.o: src/parser.c
	$(CC) $(CFLAGS) -c $< -o $@

eval.o: src/eval.c
	$(CC) $(CFLAGS) -c $< -lm -o $@

inputproc.o: src/inputproc.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ARQUIVO) *.o
