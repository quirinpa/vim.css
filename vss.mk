gcc-vss := gcc ${CFLAGS} -E -P -nostdinc -undef -x c
vss-path ?= .
vss-out ?= vim.css
vss-color ?= c.txt
vss-CFLAGS-y := -I${srcdir} -I${vss-path}
# vss-exe := t c
vss-clean-y := ./t.h ./c.h ./bin/t ./bin/c ${vss-out}

$(vss-out): ./t.h ./c.h ./vss.config.h
	gcc ${vss-CFLAGS-y} -E -P -nostdinc -undef -x c ./vss.config.h > $@

./t.h:
	${vss-path}/bin/t > $@

./c.h:
	${vss-path}/bin/c ${vss-color} > $@

clean:
	-rm ${vss-clean-y} >/dev/null 2>&1

PHONY: clean

$(vss-out): $(srcdir)/t.h $(srcdir)/c.h
$(vss-out): $(vss-path)/vss.h $(vss-path)/utils.h
$(vss-out): $(vss-path)/s.h $(vss-path)/h.h
$(vss-out): $(vss-path)/text.h $(vss-path)/size.h
$(vss-out): $(vss-path)/alignment.h $(vss-path)/round.h
