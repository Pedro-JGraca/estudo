#macros
CC=						g++
LD=						g++

CFLAGS=		 			-Wall -g -c -I/usr/include/python3.8
LFLAGS=		 			-Wall
LFLAGS_AFTER= 			-lpython3.8

MAIN_OBJS=				main.o
MANAGER_OBJS=			manager.o

OBJECTS=				$(MAIN_OBJS)\
						$(MANAGER_OBJS)

MAIN_FILE=				main.cpp
MANAGER_FILE=			manager.cpp


FILES=	 				$(MAIN_FILE)


EXEC= botnet

#rules

all:					$(EXEC)\
						$(OBJECTS)\
						$(FILES)

$(EXEC): $(OBJECTS)
	$(LD) $(LFLAGS) $(OBJECTS) -o $@ $(LFLAGS_AFTERS)

$(MAIN_OBJS): 			$(MAIN_FILE)

$(MANAGER_OBJS):		$(MANAGER_FILE)

$(OBJECTS): 
	$(CC) $(CFLAGS) $? -o $@

clean:
	rm $(OBJECTS)
clean-exec:
	rm $(EXEC)
clean-all:
	rm $(OBJECTS)
	rm $(EXEC)