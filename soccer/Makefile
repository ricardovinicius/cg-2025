CC = gcc
CFLAGS = -Wall -I./lib -I./src -g
LDFLAGS = -lGL -lGLU -lglut -lm

SRC = $(wildcard src/*.c src/entities/*.c src/scenes/*.c)
OBJ = $(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) -o main $(OBJ) $(LDFLAGS)

clean:
	rm -f src/*.o src/**/*.o main
