#macros de marcacao
CC=				g++
LD=				g++

CFLAGS= 		-Wall -c
LFLAGS= 		-Wall

MAIN_OBJS=		main.o
AGENDA_OBJS=	agenda.o

OBJETOS=		$(MAIN_OBJS)\
				$(AGENDA_OBJS)

EXEC=	agendador		


#macros de regras
ALL = 		compila\
			linka

MAIN =		main-compile
AGENDA =	agenda-compile

#regras
all: $(ALL)

compila: 	$(MAIN)\
			$(AGENDA)

main-compile:
	$(CC) $(CFLAGS) main.cpp -o $(MAIN_OBJS)
agenda-compile:
	$(CC) $(CFLAGS) agenda.cpp -o $(AGENDA_OBJS)

linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)