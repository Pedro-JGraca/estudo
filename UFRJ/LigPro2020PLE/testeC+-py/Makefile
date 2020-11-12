#macros
CC=						g++
LD=						g++

CFLAGS=		 			-Wall -g -c -I/usr/include/python3.8
LFLAGS=		 			-Wall
LPOSFLAGS=				-lpython3.8

MAIN_OBJS=				main.o
CPP4PY_CLASS_OBJS=		cpp4py-class.o

OBJETOS=				$(MAIN_OBJS)\
						$(CPP4PY_CLASS_OBJS)

MAIN_ARQ=				main.cpp
CPP4PY_CLASS_ARQ=		cpp4py-class.cpp

ARQUIVOS=	 			$(MAIN_ARQ)\
						$(CPP4PY_CLASS_ARQ)


EXEC= cpp4py-class	

#regras
all:					$(EXEC)\
						$(OBJETOS)\
						$(ARQUIVOS)

$(EXEC): $(OBJETOS)
	$(LD) $(LFLAGS) $(OBJETOS) -o $@ $(LPOSFLAGS)

compila:	 			$(OBJETOS)

$(MAIN_OBJS): 			$(MAIN_ARQ)

$(CPP4PY_CLASS_OBJS):	$(CPP4PY_CLASS_ARQ)


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