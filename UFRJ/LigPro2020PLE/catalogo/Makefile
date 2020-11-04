#macros
CC=						g++
LD=						g++

CFLAGS= 				-Wall -c
LFLAGS= 				-Wall

MAIN_OBJS=				main.o
PROXY_CATALOGO_OBJS=	proxyCatalogo.o
CATALOGO_OBJS=			Catalogo.o

OBJETOS=		$(MAIN_OBJS)\
				$(PROXY_CATALOGO_OBJS)\
				$(CATALOGO_OBJS)

MAIN_ARQ=				main.cpp
PROXY_CATALOGO_ARQ=		classes/proxyCatalogo.cpp
CATALOGO_ARQ=			classes/catalogo.cpp

ARQUIVOS= 		$(MAIN_ARQ)\
				$(PROXY_CATALOGO_ARQ)\
				$(CATALOGO_ARQ)

EXEC= catalogo		

#regras
all:	$(EXEC)\
		$(OBJETOS)\
		$(ARQUIVOS)

$(EXEC): $(OBJETOS)
	$(LD) $(LFLAGS) $(OBJETOS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $<

compila: 	$(OBJETOS)

$(MAIN_OBJS):
	$(CC) $(CFLAGS) $(MAIN_ARQ) -o $(MAIN_OBJS)
$(PROXY_CATALOGO_OBJS): 
	$(CC) $(CFLAGS) $(PROXY_CATALOGO_ARQ) -o $(PROXY_CATALOGO_OBJS)
$(CATALOGO_OBJS): 
	$(CC) $(CFLAGS) $(CATALOGO_ARQ) -o $(CATALOGO_OBJS)


linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)