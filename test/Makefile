all: build/pull_server

build:
	mkdir -p build

build/pull_server: build pull_server.c
	gcc -o build/pull_server pull_server.c -lzmq