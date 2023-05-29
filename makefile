all : calc

#COMPILATION SETTINGS
CC=gcc
CFLAGS=-g
LDLIBS=-lreadline

#DIRECTORIES
OBJDIR=obj
SRCDIR=src
INCDIR=include

#FILES
EXEC=calc
OBJ=obj/operation.o obj/stack.o obj/calc.o

.PHONY: all run force clean

all : $(EXEC)

$(OBJDIR)/operation.o: include/operation.h src/operation.c
	$(CC) $(CFLAGS) -c src/operation.c -o $(OBJDIR)/operation.o

$(OBJDIR)/stack.o: include/stack.h src/stack.c
	$(CC) $(CFLAGS) -c src/stack.c -o $(OBJDIR)/stack.o

$(OBJDIR)/calc.o: src/calc.c
	$(CC) $(CFLAGS) -c src/calc.c -o $(OBJDIR)/calc.o

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LDLIBS)

run:
	make --always-make
	./calc

force:
	make --always-make

clean: 
	rm -f obj/*.o
	rm -f calc