OS := $(shell uname -s)
BIN := build/$(OS)/pong

run: $(BIN)
	./$(BIN)

$(BIN): pong.c
	mkdir -p build/$(OS) && \
		cc -std=c99 -pedantic -Wall -Wextra -o $(BIN) pong.c
