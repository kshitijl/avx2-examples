CC=g++ -std=c++11 -mavx2

bin/01-hello: examples/01-hello.c
	$(CC) examples/01-hello.c -o bin/01-hello
