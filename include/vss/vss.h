#include "utils.h"

#include "t.h"
#include "s.h"
#include "c.h"
#include "h.h"

#define PI 3.1415
#define BH(_s) (S_ ## _s + RP(_s))
#define RP(_s) (S_ ## _s / PI)

#ifdef CONFIG_VARS
:root {
	VARS(T, TS)

	VARS(S, SS)

	VARS(C, CS)

	VARS(H, HS)

	--RPxl: RP(xl);
	--BHxl: BH(xl);
}
#endif

#include "text.h"
#include "size.h"
#include "alignment.h"

#ifdef CONFIG_ROUND
#include "round.h"
#endif

label > input, label > textarea { display: block; }

.fw input, .fw select, .fw textarea { width: 100%; }
.fw input, .fw textarea { width: calc(100% - 2 * CONFIG_IPH - 2px); }
input, textarea { padding: 6px CONFIG_IPH; }

button, a, *[ng-click] { cursor: pointer; user-select: none; }
.hid { display: none !important; }
body { margin: 0 }
/* table { width: 100%; } */
* {
	font-family: inherit;
}

#define HOVER_SHADOW(_selector, _shadow, _ease, _other) \
	_selector :: after { \
		box-shadow: _shadow; transition: opacity _ease; \
		position: absolute; left: 0; right: 0; top: 0; bottom: 0; \
		opacity: 0; content: ''; _other \
	} \
	_selector:hover::after { opacity: 1; }

button.round {
	padding: 0;
}
button.round::after {
	border-radius: 50%;
}

HOVER_SHADOW(
	button:not(:disabled),
	0 5px 15px rgba(0, 0, 0, 0.3),
	0.3s ease-in-out,
	border-radius: S_s
)

.dn { display: none !important; }
script { display: none !important; }
