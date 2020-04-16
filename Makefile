INSTALL ?= install
DESTDIR ?= /srv/http/bt
srcdir := .

all: ./bin/ ./bin/t ./bin/c

./bin/:
	mkdir bin

./bin/t: t.c
	cc t.c -o $@

./bin/c: c.c
	cc c.c -o $@

clean:
	-rm -rf bin

PHONY: clean
