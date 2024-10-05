CC = gcc
CFLAGS = -Wall
OBJ = compiler.o lexer.o parser.o

all: compiler.exe

compiler.exe: $(OBJ)
	$(CC) $(CFLAGS) -o compiler.exe $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o compiler.exe
