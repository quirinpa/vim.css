#define CONFIG_IPH 12px
#define CONFIG_ROUND
#define CONFIG_VARS
#include "vss/vss.h"

#define LSS s, , m, l

CALL(TEXT_SIZE, TS)
CALL(BG_COLOR, CS)
CALL(COLOR, CS)
CALL(BO_COLOR, CS)
CALL(SIZE, SS)
CALL(PADDING, SS)
CALL(DIR_PADDING, SS)
CALL(ABS_PADDING, SS)
CALL(CENTER_ABS_V, SS)

CALL(HORIZONTAL, LSS)
CALL(VERTICAL, LSS)

CALL(MARGIN, SS)
CALL(ROUND_T, SS)
CALL(ROUND_EDGE, SS)
ROUND_PADDING( , l)
