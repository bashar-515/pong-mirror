OS := $(shell uname -s)
BIN := build/$(OS)/main

run: $(BIN)
	./$(BIN)

$(BIN): main.c
	mkdir -p build/$(OS) && \
		cc -std=c99 -pedantic -Wall -Wextra -o $(BIN) main.c
