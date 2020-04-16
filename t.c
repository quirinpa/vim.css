#include <stdio.h>
#include <unistd.h>
#include <string.h>

static char *label[] = { "xs", "s", "", "m", "ml", "l", "xl", "xxl", "Xl", "xXl", "Xxl", "XXl", "L" };
static const int l = sizeof(label) / sizeof(char *);

static float f(float x, float a, float b, float c, float d) {
	return ((((a * x) + b) * x) + c) * x + d;
}

extern int opterr;

int main(int argc, char *argv[]) {
	float a = 0.113f, b = -0.6f, c = 4, d = 6, m = 0.87f;
	int i = 0;
	char name_ch = 'T', ch;

	opterr = 0;
	while ((ch = getopt(argc, argv, "a::b::c::d::m::")) != -1) {
		switch (ch) {
			case 'a':
				sscanf(optarg, "%f", &a);
				break;
			case 'b':
				sscanf(optarg, "%f", &b);
				break;
			case 'c':
				sscanf(optarg, "%f", &c);
				break;
			case 'd':
				sscanf(optarg, "%f", &d);
				break;
			case 'm':
				sscanf(optarg, "%f", &m);
				break;
		}
	}

	if (optind < argc)
		name_ch = argv[optind][0];

	/* printf("/1* OPTIND %d argv %s *1/", optind, argv[optind]); */

	printf(
		"/* x = i * %.3f; f(x) = %.3f * x ^ 3"
		" + %.3f * x ^ 2 + %.3f * x + %.3f */\n\n",
		m, a, b, c, d
	);

	printf("#ifndef %cS_N\n#define %cS_N %d\n#define %cS ", name_ch, name_ch, l, name_ch);
	for (;;) {
		printf("%s", label[i]);
		i++;
		if (i >= l)
			break;
		printf(", ");
	}
	putchar('\n');

	for (i = 1; i <= l; i++)
		printf("#define %c_%s\t%0.1fpx\n", name_ch, label[i - 1], f(m * i, a, b, c, d));

	printf("#endif\n");

	return 0;
}

