q.css: t.h style.css
	# q.css
	sed 's/^\/\*gcc//g;s|^\*/$$||g' style.css | \
		gcc -C -E -H -P -nostdinc -undef -x c - | sed 's/\$$/#/g' > $@
	# -q.css

./t: t.c
	# t
	cc t.c -o $@

./t.h: t.c ./t
	# t.h
	./t > t.h

clean:
	rm t.h t q.css

PHONY: clean
