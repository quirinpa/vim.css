#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include "s.h"
#include "d.h"

/* .x._ ## _s > input { width: calc(50% - 2 * CONFIG_IPH - S(_s) / 2 - 2px); } */

#define HDIVN(_d) \
	.x_ ## _d._n > * { \
		width: calc(100% / _d); \
	}

._n:not(.f) > :not(.f) { display: inline-block; }
._n > .f { display: inline-flex; }
CALL(HDIVN, DD)

#define HDIV(_s, _d) \
	.x_ ## _d._ ## _s > * { \
		width: calc((100% - S(_s) * (_d - 1)) / _d); \
	}

#define HORIZONTAL(_s) \
	._ ## _s:not(.f) > * { margin-left: S(_s); } \
	._ ## _s:not(.f) > :first-child { margin-left: 0; } \
	._ ## _s:not(.f) > :not(.f) { display: inline-block; } \
	._ ## _s > .f { display: inline-flex; } \
	._ ## _s.f { column-gap: S(_s); } \
	._ ## _s.f > * { margin: 0; } \
	CALL1(HDIV, _s, DD)

#define VDIVN(_d) \
	.xv ## _d.vn > * { \
		height: calc(100% / _d); \
	}

.vn.f:not(.fw) { flex-direction: column; }
CALL(VDIVN, DD)

#define VDIV(_s, _d) \
	.xv ## _d.v ## _s > * { \
		height: calc((100% - S(_s) * (_d - 1)) / _d); \
	}

#define VERTICAL(_s) \
	.v ## _s:not(.f) > * { margin-top: S(_s); } \
	.v ## _s:not(.f) > :first-child { margin-top: 0; } \
	.v ## _s.f { row-gap: S(_s); } \
	.v ## _s.f:not(.fw) { flex-direction: column; } \
	.v ## _s.f > * { margin: 0; } \
	CALL1(VDIV, _s, DD)

#define TABLE_VERTICAL(_s) \
	table.v ## _s { border-spacing: 0 S(_s); border-collapse: separate; } \
	table.v ## _s > * { margin_top: 0; }

.c > * { vertical-align: middle; }
.f.c { align-items: center; }

.f { display: flex; }
.fw { flex-wrap: wrap; }
.f.vn { flex-direction: column; }
.fg { flex-grow: 1; }
.fg- { flex-grow: 0 !important; }
.fgc > * { flex-grow: 1; }

.fic { align-items: center; }
.fis { align-items: stretch; }
.fik { align-items: flex-start; }
.fij { align-items: flex-end; }

.fcc { justify-content: center; }
.fck { justify-content: flex-start; }
.fcj { justify-content: flex-end; }
.fcsb { justify-content: space-between; }

.fak { align-self: flex-start; }
.faj { align-self: flex-end; }
.fac { align-self: center; }

.rel { position: relative; }
.abs { position: absolute; }
.ah { left: 0; }
.aj { bottom: 0; }
.ak { top: 0; }
.al { right: 0; }

.tcv {
	display: inline-flex !important;
	flex-direction: column;
	justify-content: center;
	text-align: center;
}

.dn { display: none! important; }

#endif
