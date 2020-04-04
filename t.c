#include <stdio.h>

static char *label[] = { "xs", "s", "", "m", "ml", "l", "xl", "xxl", "Xl", "xXl", "Xxl", "XXl" };
static const int l = sizeof(label) / sizeof(char *);
static const float a = 0.113f, b = 0.6f, c = 4, d = 6;

static float f(float x) {
	return ((((a * x) - b) * x) + c) * x + d;
}

const char fmt[] = (
		"#ifndef T_H\n#define T_H\n#include \"pop.h\"\n"
		"/* f(x) = %.3f * x ^ 3 - %.1f * x ^ 2 + %.0f * x + %.0f */\n\n"
	    );

int main() {
	int i = 0;

	printf("/* f(x) = %.3f * x ^ 3 - %.1f * x ^ 2 + %.0f * x + %.0f */\n\n", a, b, c, d);

	printf("#ifndef TS_H\n#define TS_N %d\n#define TS ", l);
	for (;;) {
		printf("%s", label[i]);
		i++;
		if (i >= l)
			break;
		printf(", ");
	}
	putchar('\n');

	for (i = 1; i <= l; i++)
		printf("#define T_%s\t%0.1fpx\n", label[i - 1], f(0.93f * i));

	printf("#endif\n");

	return 0;
}

