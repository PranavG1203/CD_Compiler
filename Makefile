CC = gcc
CFLAGS = -Wall

all: compiler.exe

compiler.exe: compiler.o lexer.o parser.o
	$(CC) -o compiler.exe compiler.o lexer.o parser.o

compiler.o: compiler.c lexer.h parser.h
	$(CC) $(CFLAGS) -c compiler.c

lexer.o: lexer.c lexer.h tokens.h
	$(CC) $(CFLAGS) -c lexer.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

clean:
	rm -f *.o compiler.exe
