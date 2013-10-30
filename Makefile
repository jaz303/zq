all: build/zq

build:
	mkdir -p build

build/zq: build src/main.c
	gcc --std=c99 -o build/zq src/main.c -lzmq

clean:
	rm -rf build