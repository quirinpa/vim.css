gcc-vss := gcc ${CFLAGS} -E -P -nostdinc -undef -x c
vss-path ?= .
vss-out ?= ../vim.css
vss-color ?= c.txt
vss-dir ?= ${srcdir}/vss
vss-CFLAGS-y := -I${vss-dir} -I${vss-path}
vss-clean-y := ./t.h ./c.h ${vss-out}

all: $(vss-out)

$(vss-out): ./t.h ./c.h ./vss.config.h
	gcc ${vss-CFLAGS-y} -E -P -nostdinc -undef -x c ./vss.config.h > $@

./t.h:
	${vss-path}/bin/t ${vss-t-args} > $@

./c.h:
	${vss-path}/bin/c ${vss-color} > $@

clean:
	-rm ${vss-clean-y} >/dev/null 2>&1

PHONY: clean

$(vss-out): $(vss-dir)/t.h $(vss-dir)/c.h
$(vss-out): $(vss-path)/vss.h $(vss-path)/utils.h
$(vss-out): $(vss-path)/s.h $(vss-path)/h.h
$(vss-out): $(vss-path)/text.h $(vss-path)/size.h
$(vss-out): $(vss-path)/alignment.h $(vss-path)/round.h
