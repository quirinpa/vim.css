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

#ifdef CONFIG_ROUND
#include "round.h"
#endif

label > input, label > textarea { display: block; }

.fw input, .fw select, .fw textarea { width: 100%; }
.fw input { width: calc(100% - 2 * CONFIG_IPH - 2px); }
input, textarea { padding-left: 6px CONFIG_IPH; }

main > .abs.J { bottom: S_; }
input, textarea { color: C_black; }
.click { cursor: pointer; user-select: none; }
