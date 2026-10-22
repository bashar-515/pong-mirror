uname_s := $(shell uname -s)
uname_m := $(shell uname -m)

ifeq ($(uname_s),Darwin)
    os := macos
else ifeq ($(uname_s),Linux)
    os := linux
else
    $(error unsupported operating system: $(uname_s))
endif

ifeq ($(uname_m),x86_64)
    arch := x86_64
else ifneq ($(filter arm64 aarch64,$(uname_m)),)
    arch := arm64
else
    $(error unsupported architecture: $(uname_m))
endif

flags := -std=c99 -pedantic -Wall -Wextra -Isrc

ifeq ($(os),linux)
	flags += -D_POSIX_C_SOURCE=200809L
endif

bin := build/$(os)-$(arch)/pong

.PHONY: all

all: $(bin)

srcs := src/main.c $(shell find src/platform/$(os) -name '*.c')
hdrs := $(wildcard src/*.h src/platform/*.h) \
		$(shell find src/platform/$(os) -name '*.h')

$(bin): $(srcs) $(hdrs)
	mkdir -p $(@D) && \
		$(CC) $(flags) -o $@ $(srcs)

.PHONY: run

run: $(bin)
	$(bin)
