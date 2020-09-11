#ifndef SIZE_H
#define SIZE_H

.shfv { width: 100vw; }
.svfv { height: 100vh; }
.s_f { width: 100%; }
.svf { height: 100%; }
.sf { width: 100%; height: 100%; }
.sfv { min-height: 100vh; width: 100vw; height: 100vh; }
.sK_f { max-width: 100%; }
.sKvf { max-height: 100%; }
.sJ_f { min-width: 100%; }
.sJvf { min-height: 100%; }

#define SIZE(_s) \
	.sv ## _s, .s ## _s { height: S(_s); } \
	.s_ ## _s, .s ## _s { width: S(_s); } \
	.st ## _s { line-height: S(_s); } \
	.sk_ ## _s { max-width: S(_s); } \
	.skv ## _s { max-height: S(_s); }

#define PADDING(_s) \
	.p ## _s { padding: S(_s); } \
	.p ## _s > .W { width: calc(100% - 2 * S(_s)); }

#define DIR_PADDING(_s) \
	.p_ ## _s { padding-left: S(_s); padding-right: S(_s); } \
	.pv ## _s { padding-top: S(_s); padding-bottom: S(_s); } \
	.ph ## _s { padding-left: S(_s); } \
	.pj ## _s { padding-bottom: S(_s); } \
	.pk ## _s { padding-top: S(_s); } \
	.pl ## _s { padding-right: S(_s); }

#define ABS_PADDING(_s) \
	.p_ ## _s > .abs.dh { left: S(_s); } \
	.pv ## _s > .abs.dj { bottom: S(_s); } \
	.pv ## _s > .abs.dk { top: S(_s); } \
	.p_ ## _s > .abs.dl { right: S(_s); } \
	.p_ ## _s > .abs.W { width: calc(100% - S(_s) * 2); } \
	\
	.p ## _s > .abs.dh { left: S(_s); } \
	.p ## _s > .abs.dj { bottom: S(_s); } \
	.p ## _s > .abs.dk { top: S(_s); } \
	.p ## _s > .abs.dl { right: S(_s); } \
	.p ## _s > .abs.W { width: calc(100% - S(_s) * 2); } \
	\
	.ph ## _s > .abs.dh { left: S(_s); } \
	.pj ## _s > .abs.dj { bottom: S(_s); } \
	.pk ## _s > .abs.dk { top: S(_s); } \
	.pl ## _s > .abs.dl { right: S(_s); } \

#define CENTER_ABS_V(_s) \
	.abs.s ## _s, .abs.sv ## _s { top: calc(50% - S(_s) / 2); }

#define CENTER_ABS_VP(_s, _pK, _pJ) \
	.pk ## _pK.pj ## _pJ > .abs.s ## _s { top: calc((100% - S(_s) + S(_pK) - S(_pJ)) / 2); }

#define TABLE_PADDING(_s) \
	table.P ## _s > tbody > tr > td { padding: calc(S(_s) / 2); } \
	table.P ## _s th { padding-top: calc(S(_s) / 2); padding-bottom: calc(S(_s) / 2); } \
	table.P ## _s > tbody > tr > td:first-child { padding-left: S(_s); } \
	table.P ## _s > tbody > tr > td:last-child { padding-right: S(_s); } \
	table.P ## _s > tbody > tr > td { padding: S(_s) calc(S(_s) / 2); }

#define MARGIN(_s) \
	.mh ## _s { margin-left: S(_s) !important; } \
	.mj ## _s { margin-bottom: S(_s) !important; } \
	.mk ## _s { margin-top: S(_s) !important; } \
	.ml ## _s { margin-right: S(_s) !important; }

/* #define FW_PADDING(_s) \ */
/* .p > .fw { width: calc(100% - 2 * S(_s)); } */

#endif
