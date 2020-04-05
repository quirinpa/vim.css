#ifndef SIZE_H
#define SIZE_H

.W { width: 100%; }

#define SIZE(_s) \
	.sv ## _s, .s ## _s { height: S(_s); } \
	.sh ## _s, .s ## _s { width: S(_s); } \
	.st ## _s { line-height: S(_s); }

#define PADDING(_s) \
	.p ## _s { padding: S(_s); } \
	.p ## _s > .W { width: calc(100% - 2 * S(_s)); }

#define ABS_PADDING(_s) \
	.p ## _s > .abs.H { left: S(_s); } \
	.p ## _s > .abs.J { bottom: S(_s); } \
	.p ## _s > .abs.K { top: S(_s); } \
	.p ## _s > .abs.L { right: S(_s); }

#define CENTER_ABS_V(_s) \
	.abs.s ## _s, .abs.sv ## _s { top: calc(50% - S(_s) / 2); }

#define TABLE_PADDING(_s) \
	table.P ## _s > tbody > tr > td { padding: calc(S(_s) / 2); } \
	table.P ## _s th { padding-top: calc(S(_s) / 2); padding-bottom: calc(S(_s) / 2); } \
	table.P ## _s > tbody > tr > td:first-child { padding-left: S(_s); } \
	table.P ## _s > tbody > tr > td:last-child { padding-right: S(_s); } \
	table.P ## _s > tbody > tr > td { padding: S(_s) calc(S(_s) / 2); }

CALL_OF(S, SIZE, SS)
CALL_OF(S, PADDING, SS)

CALL_2(TABLE_PADDING, s, )
CALL_2(CENTER_ABS_V, l, )
CALL_2(ABS_PADDING, xl, )

/* #define FW_PADDING(_s) \ */
/* .p > .fw { width: calc(100% - 2 * S(_s)); } */

#endif
