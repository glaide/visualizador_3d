#Glaide de Lara Oliveira
#GRR20184567

CC=gcc
#flags para warning, depuração 
CFLAGS=-g -Wall 

#flag para sdl
LDLIBS = -lSDL2 -lSDL2_gfx -lm

#regras de ligação
wire = wireframe.o graphics.o objread.o perspect.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) 

#variavel geral
all: wireframe

#regras de compilação
wireframe: $(wire)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)


.PHONY:	clean
#remove os arquivos temporarios

clean: 

	rm *.o 

#remove os executaveis
purge: 

	rm wireframe
