src=$(patsubst %.c,%.o,$(wildcard src/*.c))
tests=$(patsubst %.c,%.o,$(wildcard tests/*.c))

build: $(src) $(tests)
	gcc -std=c99 -o reverse-polish-notation $(src) $(tests) -lcheck `pkg-config --cflags --libs check`


test: build
	./reverse-polish-notation

clean:
	rm -f reverse-polish-notation
	rm -f src/*.o tests/*.o

