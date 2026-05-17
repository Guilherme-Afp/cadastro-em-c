CC = gcc
CFLAGS = -Iinclude

all:
	$(CC) src/*.c $(CFLAGS) -o cadastro

run:
	.\cadastro.exe

clean:
	del cadastro.exe