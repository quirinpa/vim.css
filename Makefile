INSTALL ?= install
DESTDIR ?= /srv/http/bt
srcdir := .

include vss.mk

install: vim.css
	${INSTALL} vim.css ${DESTDIR}/styles

PHONY: install
