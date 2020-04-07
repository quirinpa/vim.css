INSTALL ?= install
DESTDIR ?= /srv/http/bt
srcdir := .

include vss.mk

install: vim.css
	${INSTALL} vim.css ${DESTDIR}/styles

PHONY: install

# DO NOT DELETE

./vss.o: utils.h autoconfig.h t.h s.h c.h h.h text.h size.h alignment.h
./vss.o: fixed.h round.h
