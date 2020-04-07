gcc-vss := gcc ${CFLAGS} -E -P -nostdinc -undef -x c
vss-path ?= .
vss-dirs := bin
vss-CFLAGS-y := -I${srcdir} -I${vss-path}
# vss-exe := t c
vss-clean-y := ./t.h ./c.h ./bin/t ./bin/c vim.css

vim.css: ${vss-dirs} ./t.h ./c.h ./vss.config.h
	gcc ${vss-CFLAGS-y} -E -P -nostdinc -undef -x c ./vss.config.h > $@

$(vss-dirs):
	mkdir -p $@

./t.h: ./bin/t ${vss-path}/t.c
	./bin/t > $@

./c.h: ./bin/c ${vss-path}/c.c
	./bin/c > $@

./bin/t: ${vss-path}/t.c
	cc ${vss-path}/t.c -o $@

./bin/c: ${vss-path}/c.c
	cc ${vss-path}/c.c -o $@

clean:
	rm ${vss-clean-y}

depend:
	makedepend ${vss-CFLAGS-y} $(srcdir)/vss.h

PHONY: clean depend
