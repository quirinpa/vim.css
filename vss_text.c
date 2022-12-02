#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/queue.h>

struct value {
	int value;
	STAILQ_ENTRY(value) entry;
};

STAILQ_HEAD(value_stailq, value);

static char const * const prefix = "VAR_TEXT_SIZE";
static char *label[] = { "xs", "s", "", "m", "ml", "l", "xl", "xxl", "ll", "xll", "xxll", "lll", "xlll" };
static const int l = sizeof(label) / sizeof(char *);

static int f(float x, float a, float b, float c, float d) {
	return (int) (((((a * x) + b) * x) + c) * x + d);
}

extern int opterr;

int main(int argc, char *argv[]) {
	struct value_stailq values;
	float a = 0.113f, b = -0.6f, c = 4, d = 6, m = 0.87f;
	int i = 0;
	char ch;

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

	/* if (optind < argc) */
	/* 	name_ch = argv[optind][0]; */

	/* printf("/1* OPTIND %d argv %s *1/", optind, argv[optind]); */

	STAILQ_INIT(&values);

	printf(
		"/* x = i * %.3f; f(x) = %.3f * x ^ 3"
		" + %.3f * x ^ 2 + %.3f * x + %.3f */\n",
		m, a, b, c, d
	);

	printf("#ifndef TEXT_SIZES_H\n#define TEXT_SIZES_H\n");

	for (i = 1; i <= l; i++) {
		struct value *value = (struct value *) malloc(sizeof(struct value));
		value->value = f(m * i, a, b, c, d);
		printf("#define VAL_TEXT_SIZE_%d %dpx\n", value->value, value->value);
		STAILQ_INSERT_TAIL(&values, value, entry);
	}

	printf("#define ALL_TEXT_SIZES ");

	{
		struct value *value, *value_tmp;

		STAILQ_FOREACH(value, &values, entry) {
			printf("%d", value->value);
			if (STAILQ_NEXT(value, entry))
				printf(", ");
		}
	}

	printf("\n#endif\n");
	return 0;
}

