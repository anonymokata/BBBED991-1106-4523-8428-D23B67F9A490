src=$(patsubst %.c,%.o,$(wildcard src/*.c))
tests=$(patsubst %.c,%.o,$(wildcard tests/*.c))
CC=gcc
CFLAGS=-std=c99
FLAGS=`pkg-config --cflags --libs check`

build: $(src) $(tests)
	$(CC) $(CFLAGS) -o reverse-polish-notation $(src) $(tests) -lcheck $(FLAGS)

test: build
	./reverse-polish-notation

clean:
	rm -f reverse-polish-notation
	rm -f src/*.o tests/*.o
