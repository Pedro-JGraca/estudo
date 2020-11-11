#macros
CC=						g++
LD=						g++

CFLAGS= 				-Wall -c -g
LFLAGS=		 			-Wall

MAIN_OBJS=				main.o
CADASTRO_OBJS=			cadastro.o
PACIENTE_OBJS=			paciente.o
ARVORE_OBJS=			arvore.o


OBJETOS=				$(MAIN_OBJS)\
						$(CADASTRO_OBJS)\
						$(PACIENTE_OBJS)\
						$(ARVORE_OBJS)

MAIN_ARQ=				main.cpp
CADASTRO_ARQ=			classes/cadastro.cpp
PACIENTE_ARQ=			classes/paciente.cpp
ARVORE_ARQ=				classes/arvore.cpp

ARQUIVOS= 				$(MAIN_ARQ)\
						$(CADASTRO_ARQ)\
						$(PACIENTE_ARQ)\
						$(ARVORE_ARQ)

EXEC= cadastro-pacientes		

#regras

all:					$(EXEC)\
						$(OBJETOS)\
						$(ARQUIVOS)

$(EXEC): $(OBJETOS)
	$(LD) $(LFLAGS) $? -o $@

compila: 	$(OBJETOS)

$(MAIN_OBJS): $(MAIN_ARQ)

$(CADASTRO_OBJS): $(CADASTRO_ARQ)

$(PACIENTE_OBJS): $(PACIENTE_ARQ)

$(ARVORE_OBJS): $(ARVORE_ARQ)

$(OBJETOS): 
	$(CC) $(CFLAGS) $? -o $@

linka:
	$(LD) $(LFLAGS) $(OBJETOS) -o $(EXEC)

clean:
	rm $(OBJETOS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJETOS)
	rm $(EXEC)
	rm -rf BD/
