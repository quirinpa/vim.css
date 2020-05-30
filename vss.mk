gcc-vss := gcc ${CFLAGS} -E -P -nostdinc -undef -x c
vss-out ?= ../vim.css
vss-color ?= c.txt
vss-dir := ${srcdir}/vss
PREFIX ?= /usr/local
vss-CFLAGS-y := -I${vss-dir} -I${PREFIX}/include
vss-clean-y := ./t.h ./c.h ${vss-out}

all: $(vss-out)

$(vss-out): ./t.h ./c.h ./vss.config.h
	gcc ${vss-CFLAGS-y} -E -P -nostdinc -undef -x c ./vss.config.h > $@

./t.h:
	vss_t ${vss-t-args} > $@

./c.h:
	vss_c ${vss-color} > $@

clean:
	-rm ${vss-clean-y} >/dev/null 2>&1

PHONY: clean

$(vss-out): $(vss-dir)/t.h $(vss-dir)/c.h
