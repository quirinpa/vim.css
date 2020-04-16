#include <stdio.h>

typedef char *skv[2];

static skv colors[] = {
	{ "pri", "#d1005d" }, // deepPink
	{ "blue", "#1654ff" }, // azul
	{ "dblue", "#1c3dcc" }, // blueBlue
	{ "coral", "#ff4444" },
	{ "xlgrey", "#f0f0f0" }, // veryLightPink
	{ "midnight", "#030830" },
	{ "grey", "#a8aab8" }, // lightGreyBlue
	{ "sun", "#ffd81c" }, // sunYellow
	{ "turquoise", "#00c1c5" }, // turquoiseBlue
	{ "palegrey", "#f5f5f7" }, // <remove>
	{ "white", "white" },
	{ "black", "black" },
	/* { "white48", "rgba(255, 255, 255, 0.48)" }, */
	{ "violet", "#5411dd" }, // violetBlue
	{ "emerald", "#00d170" }, // greenBlue
	{ "periwinkle", "#dbdee3" }, // lightPeriwinkle
	{ "lgrey", "#cccdd5" }, // lightBlueGrey
	{ "red", "#d10000" }, // does not exist in styleguide
};
static const int l = sizeof(colors) / sizeof(skv);

int main() {
	int i = 0;

	printf("#ifndef CS_H\n#define CS_N %d\n#define CS ", l);
	for (;;) {
		printf("%s", colors[i][0]);
		i++;
		if (i >= l)
			break;
		printf(", ");
	}
	putchar('\n');

	for (i = 0; i < l; i++)
		printf("#define C_%s %s\n", colors[i][0], colors[i][1]);

	printf("#endif\n");

	return 0;
}

