# AT

Calculadora de arcos de transição desenvolvida em C.

## Como utilizar

### No Linux
é necessário ter o `git` e o `gcc` instalados
1) faça `clone` do repositório
```
$ git clone https://github.com/gckneip/AT.git
```
2) compile
```
$ make
```
3) execute o programa, passando a expressão booleana como argumento de execução

**OBS:** utilize aspas simples
```
$ ./AT 'a*b+!a*c'
```

### No Windows
é necessário ter o `git` e o `minGW` instalados e configurados na variavel `PATH` do sistema
1) faça `clone` do repositório
```
$ git clone https://github.com/gckneip/AT.git
```
2) compile
```
$ mingw32-make
```
3) execute o programa, passando a expressão booleana como argumento de execução

**OBS:** utilize aspas simples
```
$ ./AT 'a*b+!a*c'
```
