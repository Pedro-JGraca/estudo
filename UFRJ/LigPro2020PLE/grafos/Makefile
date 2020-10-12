#macros
CC=				g++
LD=				g++

CFLAGS= 		-Wall -c
LFLAGS= 		-Wall

MAIN_OBJS=		main.o
GRAFO_OBJS=		grafo.o
ARESTA_OBJS=	aresta.o
VERTICE_OBJS=	vertice.o

OBJETOS=		$(MAIN_OBJS)\
				$(GRAFO_OBJS)\
				$(ARESTA_OBJS)\
				$(VERTICE_OBJS)

MAIN_ARQ=		main.cpp
GRAFO_ARQ=		classes/grafo.cpp
ARESTA_ARQ=		classes/aresta.cpp
VERTICE_ARQ=	classes/vertice.cpp

ARQUIVOS= 		$(MAIN_ARQ)\
				$(GRAFO_ARQ)\
				$(ARESTA_ARQ)\
				$(VERTICE_ARQ)


EXEC= grafo		

#regras
all:	$(EXEC)\
		$(OBJETOS)\
		$(ARQUIVOS)

$(EXEC): $(OBJETOS)
	$(LD) $(LFLAGS) $(OBJETOS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $<

compila: 	$(MAIN_OBJS)\
			$(GRAFO_OBJS)\
			$(ARESTA_OBJS)\
			$(VERTICE_OBJS)

$(MAIN_OBJS):
	$(CC) $(CFLAGS) $(MAIN_ARQ) -o $(MAIN_OBJS)
$(GRAFO_OBJS): 
	$(CC) $(CFLAGS) $(GRAFO_ARQ) -o $(GRAFO_OBJS)
$(ARESTA_OBJS): 
	$(CC) $(CFLAGS) $(ARESTA_ARQ) -o $(ARESTA_OBJS)
$(VERTICE_OBJS):
	$(CC) $(CFLAGS) $(VERTICE_ARQ) -o $(VERTICE_OBJS)



linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)