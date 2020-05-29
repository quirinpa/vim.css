INSTALL ?= install
INSTALL_MKDIR ?= ${PREFIX}/mk
INSTALL_BINDIR ?= ${PREFIX}/bin
INSTALL_INCDIR ?= ${PREFIX}/include/vss
srcdir := .

all: ./bin/ ./bin/vss_t ./bin/vss_c

./bin/:
	mkdir bin

./bin/vss_t: t.c
	cc t.c -o $@

./bin/vss_c: c.c
	cc c.c -o $@

clean:
	-rm -rf bin

install:
	${INSTALL} ./bin/vss_t ${INSTALL_BINDIR}
	${INSTALL} ./bin/vss_c ${INSTALL_BINDIR}
	mkdir -p ${INSTALL_MKDIR}
	${INSTALL} ./vss.mk ${INSTALL_MKDIR}
	mkdir -p ${INSTALL_INCDIR}
	${INSTALL} ./vss.h ${INSTALL_INCDIR}
	${INSTALL} ./h.h ${INSTALL_INCDIR}
	${INSTALL} ./s.h ${INSTALL_INCDIR}
	${INSTALL} ./text.h ${INSTALL_INCDIR}
	${INSTALL} ./utils.h ${INSTALL_INCDIR}
	${INSTALL} ./round.h ${INSTALL_INCDIR}
	${INSTALL} ./alignment.h ${INSTALL_INCDIR}
	${INSTALL} ./size.h ${INSTALL_INCDIR}
	${INSTALL} ./text.h ${INSTALL_INCDIR}

PHONY: clean install
