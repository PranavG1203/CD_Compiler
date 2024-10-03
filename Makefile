CC=gcc
CFLAGS=-Wall

all: compiler.exe

compiler.exe: compiler.o lexer.o parser.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	del *.o compiler.exe
