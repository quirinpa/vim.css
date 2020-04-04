INSTALL ?= install
DESTDIR ?= /srv/http/bt

q.css: t.h q.h.css
	sed 's/^\/\*gcc//g;s|^\*/$$||g' q.h.css | gcc -E -P -nostdinc -undef -x c - | sed 's/\$$/#/g' > $@

./t: t.c
	cc t.c -o $@

./t.h: t.c ./t
	./t > t.h

clean:
	rm t.h t q.css

install: q.css
	${INSTALL} q.css ${DESTDIR}/styles

PHONY: clean install
