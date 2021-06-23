CC = gcc
CCFLAGS = -Wall -static

.PHONY: all clean build-client build-server

all: build

build: build-client build-server

build-client:
	${CC} ${CCFLAGS} src/chall.c src/checks.c -o chall

build-server:
	${CC} ${CCFLAGS} -s src/chall-server.c src/checks.c -o chall-server

clean:
	-rm -r chall chall-server
