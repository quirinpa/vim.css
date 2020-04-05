INSTALL ?= install
DESTDIR ?= /srv/http/bt

q.css: main.h
	gcc -E -P -nostdinc -undef -x c main.h | sed 's/\$$/#/g' > $@

./t: t.c
	cc t.c -o $@

./t.h: t.c ./t
	./t > t.h

clean:
	rm t.h t q.css

install: q.css
	${INSTALL} q.css ${DESTDIR}/styles

depend:
	makedepend main.h

PHONY: clean install depend
# DO NOT DELETE

main.o: utils.h autoconfig.h t.h s.h c.h h.h text.h size.h alignment.h
main.o: fixed.h
