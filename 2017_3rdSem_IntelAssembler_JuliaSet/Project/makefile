CC = gcc
CFLAGS = -Wall -m64

all: main.o assembler.o
	$(CC) $(CFLAGS) -o bff main.o assembler.o `allegro-config --shared`
main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c
assembler.o: assembler.s
	nasm -f elf64 -o assembler.o assembler.s
clean:
	rm -f *.o

