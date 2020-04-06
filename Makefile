INSTALL ?= install
DESTDIR ?= /srv/http/bt

vim.css: t.h c.h main.h
	gcc ${CFLAGS} -E -P -nostdinc -undef -x c main.h > $@

t: t.c
	cc t.c -o $@

c: c.c
	cc c.c -o $@

t.h: t.c t
	./t > t.h

c.h: c.c c
	./c > c.h

clean:
	rm t.h t c.h c vim.css

install: vim.css
	${INSTALL} vim.css ${DESTDIR}/styles

depend:
	makedepend ${CFLAGS} main.h

PHONY: clean install depend
# DO NOT DELETE

main.o: utils.h autoconfig.h t.h s.h c.h h.h text.h size.h alignment.h
main.o: fixed.h
