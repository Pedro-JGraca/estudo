#macros
CC=				g++
LD=				g++

CFLAGS= 		-Wall -c
LFLAGS= 		-Wall

MAIN_OBJS=		main.o
COVID_OBJS=		covid.o
ESTADUAL_OBJS=	estadual.o
NACIONAL_OBJS=	nacional.o

OBJETOS=		$(MAIN_OBJS)\
				$(COVID_OBJS)\
				$(ESTADUAL_OBJS)\
				$(NACIONAL_OBJS)

EXEC=	AnalisadorCovid		

#regras
all: $(EXEC)

$(EXEC): $(OBJETOS)
	$(LD) $(LFLAGS) $(OBJETOS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $<

compila: 	$(MAIN_OBJS)\
			$(COVID_OBJS)\
			$(ESTADUAL_OBJS)\
			$(NACIONAL_OBJS)

$(MAIN_OBJS):
	$(CC) $(CFLAGS) main.cpp -o $(MAIN_OBJS)
$(COVID_OBJS): 
	$(CC) $(CFLAGS) classes/covid.cpp -o $(COVID_OBJS)
$(ESTADUAL_OBJS): 
	$(CC) $(CFLAGS) classes/estadual.cpp -o $(ESTADUAL_OBJS)
$(NACIONAL_OBJS): $(ESTADUAL_OBJS)
	$(CC) $(CFLAGS) classes/nacional.cpp -o $(NACIONAL_OBJS)

linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)