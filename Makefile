CC=g++ -std=c++11 -mavx2

all: bin/01-hello bin/04-dot-product

bin/01-hello: examples/01-hello.c
	$(CC) examples/01-hello.c -o bin/01-hello

bin/04-dot-product: examples/04-dot-product.c
	$(CC) examples/04-dot-product.c -o bin/04-dot-product
