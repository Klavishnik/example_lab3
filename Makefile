CC = clang 
CFLAGS = -g -fsanitize=address -Wall -Wextra
LDFLAGS = -fsanitize=address
OUT_BIN = bin
SOURCE = main.c
LIB = lib.c

all: 	lib main	
	$(CC) -g $(LDFLAGS) lib.o main.o -o $(OUT_BIN)

lib:
	
	$(CC) -c $(LIB) $(CFLAGS) -o lib.o

main:
	$(CC) -c $(SOURCE) $(CFLAGS) -o main.o



