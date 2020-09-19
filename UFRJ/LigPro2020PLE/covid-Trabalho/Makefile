#macros de marcacao
CC=				g++
LD=				g++

CFLAGS= 		-Wall -c
LFLAGS= 		-Wall

MAIN_OBJS=		main.o
UTIL_OBJS=		util.o
#ESTADUAL_OBJS=	estadual.o

OBJETOS=		$(MAIN_OBJS)\
				$(UTIL_OBJS)
#				$(ESTADUAL_OBJS)

EXEC=	AnalisadorCovid		


#macros de regras
ALL = 		compila\
			linka

MAIN=		main-compile
UTIL=		util-compile	
#estadual =	estadual-compile

#regras
all: $(ALL)

compila: 	$(MAIN)\
			$(UTIL)
#			$(estadual)

main-compile:
	$(CC) $(CFLAGS) main.cpp -o $(MAIN_OBJS)
util-compile:
	$(CC) $(CFLAGS) classes/util.cpp -o $(UTIL_OBJS)
#estadual-compile:
#	$(CC) $(CFLAGS) estadual.cpp -o $(ESTADUAL_OBJS)

linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)