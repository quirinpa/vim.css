#include "utils.h"
#include "autoconfig.h"

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

#ifdef CONFIG_FIXED
#include "fixed.h"
#endif

.round {
	text-align: center;
	border-radius: 50%;
	vertical-align: middle;
	display: inline-block;
}

#define ROUND_TEXT(_t) \
	.round.t ## _t { \
		line-height: T_ ## _t; \
		width: T_ ## _t; \
	}

#define ROUND_PADDING(_p, _t) \
	.p ## _p.round.t ## _t { \
		line-height: T_ ## _t; \
		width: calc(T_ ## _t + 2 * S_ ## _p); \
	}

.rl { border-radius: S_l; }
.rHl { border-top-left-radius: S_l; border-bottom-left-radius: S_l; }
.rHxl { border-top-left-radius: S_xl; border-bottom-left-radius: S_xl; }
.rKLl { border-top-right-radius: S_l; }
.rHxl { border-top-left-radius: S_xl; border-bottom-left-radius: S_xl; }
/* ROUND_PADDING( , m) */
/* ROUND_PADDING( , l) */
/* ROUND_PADDING(s, l) */
/* ROUND_PADDING(xs, xl) */
/* ROUND_TEXT(l) */
/* ROUND_TEXT(ml) */
ROUND_TEXT( )
ROUND_TEXT(xl)
/* ROUND_TEXT(xXl) */
ROUND_PADDING( , xXl)
ROUND_PADDING( , Xxl)
ROUND_PADDING( l, )


label > input, label > textarea { display: block; }

.fw input, .fw select, .fw textarea { width: 100%; }
.fw input { width: calc(100% - 2 * CONFIG_IPH - 2px); }
input, textarea { padding-left: 6px CONFIG_IPH; }

main > .abs.J { bottom: S_; }
input, textarea { color: C_black; }
.click { cursor: pointer; user-select: none; }
