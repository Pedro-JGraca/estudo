#macros
CC=						g++
LD=						g++

CFLAGS= 				-Wall -c
LFLAGS=		 			-Wall

MAIN_OBJS=				main.o
CADASTRO_OBJS=			cadastro.o
PACIENTE_OBJS=			paciente.o
ARVORE_OBJS=			arvore.o

OBJETOS=				$(MAIN_OBJS)\
						$(CADASTRO_OBJS)\
						$(PACIENTE_OBJS)
#						$(ARVORE_OBJS)

MAIN_ARQ=				main.cpp
CADASTRO_ARQ=			classes/cadastro.cpp
PACIENTE_ARQ=			classes/paciente.cpp
#ARVORE_ARQ=			classes/arvore.cpp

ARQUIVOS= 			$(MAIN_ARQ)\
					$(CADASTRO_ARQ)\
					$(PACIENTE_ARQ)
#					$(ARVORE_ARQ)

EXEC= cadastro-pacientes		

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
$(CADASTRO_OBJS):
	$(CC) $(CFLAGS) $(CADASTRO_ARQ) -o $(CADASTRO_OBJS)
$(PACIENTE_OBJS):
	$(CC) $(CFLAGS) $(PACIENTE_ARQ) -o $(PACIENTE_OBJS)
#$(ARVORE_OBJS): 
#	$(CC) $(CFLAGS) $(ARVORE_ARQ) -o $(ARVORE_OBJS)

linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)
