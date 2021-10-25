# MAKEFILE
#gcc -g -o exect *.c

# Nome do compilador
CC = gcc

# Opcoes de compilacao
CFLAGS = -Wall -gcc

# Ligacao com as bibliotecas
LDFLAGS = -lm

# Wildcards eh utilizado para listar os arquivos fonte no diretorio atual
FONTES = $(wildcard *.c)

# Gera a lista dos arquivos objeto usando a lista de arquivo fonte
OBJETOS = $(FONTES: .c=.o)

# Nome do arquivo executavel
EXECUTAVEL1 = Compacta
EXECUTAVEL2 = Descompacta

# all: prog
all: $(EXECUTAVEL1) $(EXECUTAVEL2)

$(EXECUTAVEL1): 
	$(CC) -g -o $@ mainCompacta.c arvoreBinaria.c bitmap.c compacta.c descompacta.c dicionario.c listaOrdenada.c tabelaFreq.c $(LDFLAGS)

$(EXECUTAVEL2): 
	$(CC) -g -o $@ mainDescompacta.c arvoreBinaria.c bitmap.c compacta.c descompacta.c dicionario.c listaOrdenada.c tabelaFreq.c $(LDFLAGS)

#%.o: %.c
#	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf Compacta Descompacta compactado.comp

rmproper: clean
	rm -rf $(EXECUTAVEL)

#Pode substituir o 'teste.txt' para o nome do arquivo desejado
run: $(EXECUTAVEL1) $(EXECUTAVEL2)
	./$(EXECUTAVEL1) teste.txt
	./$(EXECUTAVEL2) compactado.comp

#Pode substituir o 'biblia.txt' para o nome do arquivo desejado
valgrind: $(EXECUTAVEL1) $(EXECUTAVEL2)
	valgrind ./$(EXECUTAVEL1) biblia.txt
	./$(EXECUTAVEL2) compactado.comp
