gcc-vss := gcc ${CFLAGS} -E -P -nostdinc -undef -x c
vss-path ?= .
vss-dirs := bin
vss-out ?= vim.css
vss-CFLAGS-y := -I${srcdir} -I${vss-path}
# vss-exe := t c
vss-clean-y := ./t.h ./c.h ./bin/t ./bin/c ${vss-out}

$(vss-out): ${vss-dirs} ./t.h ./c.h ./vss.config.h
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
	-rm ${vss-clean-y} >/dev/null 2>&1

PHONY: clean

$(vss-out): $(srcdir)/t.h $(srcdir)/c.h
$(vss-out): $(vss-path)/vss.h $(vss-path)/utils.h
$(vss-out): $(vss-path)/s.h $(vss-path)/h.h
$(vss-out): $(vss-path)/text.h $(vss-path)/size.h
$(vss-out): $(vss-path)/alignment.h $(vss-path)/round.h
