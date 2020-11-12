#macros
CC=				g++
LD=				g++

CFLAGS= 		-Wall -c -I/usr/include/python3.8
LFLAGS= 		-Wall
LPOSFLAGS=		-lpython3.8

MAIN_OBJS=		main.o

OBJETOS=		$(MAIN_OBJS)

MAIN_ARQ=		main.cpp

ARQUIVOS= 		$(MAIN_ARQ)


EXEC= fibonacci	

#regras
all:			$(EXEC)\
				$(OBJETOS)\
				$(ARQUIVOS)

$(EXEC): $(OBJETOS)
	$(LD) $(LFLAGS) $(OBJETOS) -o $@ $(LPOSFLAGS)

compila: 	$(OBJETOS)

$(MAIN_OBJS): $(MAIN_ARQ)

$(OBJETOS): 
	$(CC) $(CFLAGS) $? -o $@

linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC) $(LPOSFLAGS)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)
	rm -rf BD/