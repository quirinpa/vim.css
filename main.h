#include "utils.h"
#include "autoconfig.h"

#include "t.h"
#include "s.h"
#include "c.h"
#include "h.h"

:root {
	VARS(T, TS)

	VARS(S, SS)

	VARS(C, CS)

	VARS(H, HS)
}

#include "text.h"
#include "size.h"
#include "alignment.h"
#include "fixed.h"

.round {
	text-align: center;
	border-radius: 50%;
	padding: 9px;
	display: inline-flex;
}

.round.char {
	display: inline-block;
	min-width: 1rem;
	min-height: 1rem;
	line-height: 1rem;
	vertical-align: middle;
	padding: 5px;
}

label > input, label > textarea { display: block; }

.fw input, .fw select, .fw textarea { width: 100%; }
.fw input { width: calc(100% - 2 * CONFIG_IPH - 2px); }
input, textarea { padding-left: 6px CONFIG_IPH; }


main > .abs.J { bottom: var(--S); }
input, textarea { color: C_black; }
