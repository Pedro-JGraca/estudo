#macros
CC=						g++
LD=						g++

CFLAGS= 				-Wall -c
LFLAGS=		 			-Wall

MAIN_OBJS=				main.o
CADASTRO_OBJS=			cadastro.o
PACIENTE_OBJS=			paciente.o
PACIENTEESP_OBJS=		pacienteESP.o

OBJETOS=				$(MAIN_OBJS)\
						$(CADASTRO_OBJS)\
						$(PACIENTE_OBJS)\
						$(PACIENTEESP_OBJS)

MAIN_ARQ=				main.cpp
CADASTRO_ARQ=			classes/cadastro.cpp
PACIENTE_ARQ=			classes/paciente.cpp
PACIENTEESP_ARQ=		classes/pacienteESP.cpp

ARQUIVOS= 				$(MAIN_ARQ)\
						$(CADASTRO_ARQ)\
						$(PACIENTE_ARQ)\
						$(PACIENTEESP_ARQ)

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

$(PACIENTEESP_OBJS): $(PACIENTEESP_ARQ)

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
