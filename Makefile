OS := $(shell uname -s)
BIN := build/$(OS)/main

run: $(BIN)
	./$(BIN)

$(BIN): main.c
	mkdir -p build/$(OS) && cc -o $(BIN) main.c
