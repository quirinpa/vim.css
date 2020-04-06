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

#define MARGIN(_s) \
	.mH ## _s { margin-left: S(_s); } \
	.mJ ## _s { margin-bottom: S(_s); } \
	.mK ## _s { margin-top: S(_s); } \
	.mL ## _s { margin-right: S(_s); }

CALL(SIZE, SS)
CALL(PADDING, SS)
CALL(TABLE_PADDING, s, )
CALL(CENTER_ABS_V, l, )
CALL(ABS_PADDING, s, xl, )
MARGIN(l)

/* #define FW_PADDING(_s) \ */
/* .p > .fw { width: calc(100% - 2 * S(_s)); } */

#endif
