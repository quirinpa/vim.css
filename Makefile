INSTALL ?= install
INSTALL_MKDIR ?= ${PREFIX}/mk
INSTALL_BINDIR ?= ${PREFIX}/bin
INSTALL_INCDIR ?= ${PREFIX}/include/vss
srcdir := .

all: ./bin/ ./bin/vss_text ./bin/vss_color

./bin/:
	mkdir bin

./bin/vss_text: vss_text.c
	cc vss_text.c -o $@

./bin/vss_color: vss_color.c
	cc vss_color.c -o $@

clean:
	-rm -rf bin

install:
	${INSTALL} ./bin/vss_text ${INSTALL_BINDIR}
	${INSTALL} ./bin/vss_color ${INSTALL_BINDIR}
	mkdir -p ${INSTALL_MKDIR}
	${INSTALL} ./mk/vss.mk ${INSTALL_MKDIR}
	mkdir -p ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/vss.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/h.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/s.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/text.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/utils.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/round.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/alignment.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/size.h ${INSTALL_INCDIR}
	${INSTALL} ./include/vss/text.h ${INSTALL_INCDIR}

PHONY: clean install
