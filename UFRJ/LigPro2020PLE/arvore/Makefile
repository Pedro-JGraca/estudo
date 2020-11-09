#macros
CC=				g++
LD=				g++

CFLAGS= 			-Wall -c
LFLAGS= 			-Wall

MAIN_OBJS=			main.o
PROXY_ARVORE_OBJS=		proxyArvore.o
ARVORE_OBJS=			arvore.o

OBJETOS=			$(MAIN_OBJS)\
				$(PROXY_ARVORE_OBJS)\
				$(ARVORE_OBJS)

MAIN_ARQ=			main.cpp
PROXY_ARVORE_ARQ=		classes/proxyArvore.cpp
ARVORE_ARQ=			classes/arvore.cpp

ARQUIVOS= 			$(MAIN_ARQ)\
				$(PROXY_ARVORE_ARQ)\
				$(ARVORE_ARQ)

EXEC= arvore		

#regras
all:				$(EXEC)\
				$(OBJETOS)\
				$(ARQUIVOS)

$(EXEC): $(OBJETOS)
	$(LD) $(LFLAGS) $(OBJETOS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $<

compila: 	$(OBJETOS)

$(MAIN_OBJS):
	$(CC) $(CFLAGS) $(MAIN_ARQ) -o $(MAIN_OBJS)
$(PROXY_ARVORE_OBJS): 
	$(CC) $(CFLAGS) $(PROXY_ARVORE_ARQ) -o $(PROXY_ARVORE_OBJS)
$(ARVORE_OBJS): 
	$(CC) $(CFLAGS) $(ARVORE_ARQ) -o $(ARVORE_OBJS)


linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)
