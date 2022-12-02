vss-prefix ?= /usr/local
vss-path := ${vss-prefix}/bin/

srcdir ?= ..
vss-t-args ?= -a0.112 -b-0.61 -c3.9 -d6.1 -m0.88
gcc-vss := gcc ${CFLAGS} -E -P -nostdinc -undef -x c
vss-out ?= ${srcdir}/vim.css
vss-color ?= color.txt
vss-dir := ${srcdir}/vss
PREFIX ?= /usr/local
vss-CFLAGS-y := -I${vss-prefix}/include -I${vss-dir} -I${PREFIX}/include
vss-clean-y := ./text-size.h ./color.h ${vss-out}

all: $(vss-out)

$(vss-out): ./text-size.h ./color.h ./vss.config.h
	${CC} ${vss-CFLAGS-y} -E -P -nostdinc -undef -x c ./vss.config.h > $@

./text-size.h:
	${vss-path}vss_text ${vss-t-args} > $@

./color.h: ${vss-color}
	${vss-path}vss_color ${vss-color} > $@

clean:
	-rm ${vss-clean-y} >/dev/null 2>&1

PHONY: clean

$(vss-out): $(vss-dir)/text-size.h $(vss-dir)/color.h
