CC = gcc
CFLAGS = -Wall

all: compiler.exe

compiler.exe: compiler.o lexer.o parser.o variable.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o compiler.exe
