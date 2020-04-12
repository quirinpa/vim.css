#include "utils.h"

#include "t.h"
#include "s.h"
#include "c.h"
#include "h.h"

#define PI 3.1415
#define BH(_s) (S_ ## _s + RP(_s))
#define RP(_s) (S_ ## _s / PI)

:root {
	VARS(T, TS)

	VARS(S, SS)

	VARS(C, CS)

	VARS(H, HS)

	--RPxl: RP(xl);
	--BHxl: BH(xl);
}

#include "text.h"
#include "size.h"
#include "alignment.h"

#ifdef CONFIG_ROUND
#include "round.h"
#endif

label > input, label > textarea { display: block; }

.fw input, .fw select, .fw textarea { width: 100%; }
.fw input { width: calc(100% - 2 * CONFIG_IPH - 2px); }
input, textarea { padding: 6px CONFIG_IPH; }

input, textarea { color: C_black; }
.click { cursor: pointer; user-select: none; }
.hid { display: none !important; }
body { margin: 0 }
/* table { width: 100%; } */
* {
	font-family: inherit;
	/* font-weight: inherit; */
}
button {
	color: C_black;
	background-color: C_pri;
	border: none;
	box-shadow: 0 1px 2px rgba(0, 0, 0, 0.15);
	border-radius: S_s !important;
	position: relative;
}
button::after {
	content: '';
	box-shadow: 0 5px 15px rgba(0, 0, 0, 0.3);
	border-radius: S_s;
	opacity: 0;
	transition: opacity 0.3s ease-in-out;
	position: absolute;
	/* z-index: -1; */
	/* width: 100%; */
	/* height: 100%; */
	left: 0;
	top: 0;
	bottom: 0;
	right: 0;
}
button:not(:disabled):hover::after {
	opacity: 1;
}
