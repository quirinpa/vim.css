#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

enum mode_t {
	M_KEY,
	M_VALUE,
	M_COMMENT,
};

int main(int argc, char *argv[]) {
	if (argc < 2)
		return 1;

	int fd = open(argv[1], O_RDONLY);

	if (fd < 1)
		return 1;

	char buf[1024], *buf_p = buf, *key_start = buf;
	char *keys[32];

	ssize_t buf_l = read(fd, buf, sizeof(buf));
	size_t keys_l = 0;

	int i, mode = M_KEY;

	printf("#ifndef COLORS_N\n#define COLORS_N\n");
	for (; buf_p < buf + buf_l; buf_p ++) {
		switch (*buf_p) {
			case '\n':
				putchar('\n');
				key_start = buf_p + 1;
				mode = M_KEY;
				continue;

			case ' ':
				if (mode == M_KEY) {
					*buf_p = '\0';
					keys[keys_l] = key_start;
					keys_l ++;
					putchar(' ');
					mode = M_VALUE;
					continue;
				}

				mode = M_VALUE;

			default:
				if (mode == M_KEY && buf_p == key_start)
					printf("#define VAL_COLOR_");

				putchar(*buf_p);
		}
	}

	printf("#define ALL_COLORS ");
	for (i = 0;;) {
		printf("%s", keys[i]);
		i++;
		if (i >= keys_l)
			break;
		printf(", ");
	}
	printf("\n#endif\n");

	return 0;
}

