vss-prefix ?= /usr/local
vss-path := ${vss-prefix}/bin/

srcdir ?= ..
vss-t-args ?= -a0.112 -b-0.61 -c3.9 -d6.1 -m0.88
gcc-vss := gcc ${CFLAGS} -E -P -nostdinc -undef -x c
vss-out ?= ${srcdir}/vim.css
vss-color ?= c.txt
vss-dir := ${srcdir}/vss
PREFIX ?= /usr/local
vss-CFLAGS-y := -I${vss-prefix}/include -I${vss-dir} -I${PREFIX}/include
vss-clean-y := ./t.h ./c.h ${vss-out}

all: $(vss-out)

$(vss-out): ./t.h ./c.h ./vss.config.h
	${CC} ${vss-CFLAGS-y} -E -P -nostdinc -undef -x c ./vss.config.h > $@

./t.h:
	${vss-path}vss_t ${vss-t-args} > $@

./c.h: c.txt
	${vss-path}vss_c ${vss-color} > $@

clean:
	-rm ${vss-clean-y} >/dev/null 2>&1

PHONY: clean

$(vss-out): $(vss-dir)/t.h $(vss-dir)/c.h
