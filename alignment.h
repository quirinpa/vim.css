#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include "s.h"

#define HORIZONTAL(_s) \
	.h ## _s > * { margin-left: S(_s); display: inline-block; } \
	.h ## _s > :first-child { margin-left: 0; }

#define VERTICAL(_s) \
	.v ## _s { flex-direction: column; } \
	.v ## _s > * { margin-top: S(_s); display: block } \
	.v ## _s > :first-child { margin-top: 0; } \

#define TABLE_VERTICAL(_s) \
	table.v ## _s { border-spacing: 0 S(_s); border-collapse: separate; } \
	table.v ## _s > * { margin_top: 0; }

#define FLEX_VERTICAL(_s) \
	.v ## _s.f { flex-direction: column; }

#define SPLIT_HORIZONTAL(_s) \
	.x.h ## _s { overflow: hidden; } \
	.x.h ## _s > * { display: block; float: left; width: calc(50% - S(_s) / 2); } \
	.x.h ## _s > input { width: calc(50% - 2 * CONFIG_IPH - S(_s) / 2 - 2px); }

#define WRAP(_s) \
	.w ## _s { \
		display: flex; \
		flex-wrap: wrap; margin-right: calc(S(_s) * -1); \
		margin-bottom: calc(S(_s) * -1); \
	} \
	.w ## _s > * { margin-bottom: S(_s); margin-right: S(_s); }

.c > * { vertical-align: middle; }
.f.c { align-items: center; }

.f { display: flex !important; }
.f.vn { flex-direction: column; }
.fg { flex-grow: 1; }
.fg- { flex-grow: 0 !important; }
.fgc > * { flex-grow: 1; }

/* .fic { align-items: center; } */
.fis { align-items: stretch; }
.fiK { align-items: flex-start; }
.fiJ { align-items: flex-end; }

.fcc { justify-content: center; }
.fcK { justify-content: flex-start; }
.fcJ { justify-content: flex-end; }

.faK { align-self: flex-start; }
.faJ { align-self: flex-end; }

.rel { position: relative; }
.abs { position: absolute; }
.abs.H { left: 0; }
.abs.J { bottom: 0; }
.abs.K { top: 0; }
.abs.L { right: 0; }

.tcv {
	display: inline-flex !important;
	flex-direction: column;
	justify-content: center;
	text-align: center;
}

.dn { display: none! important; }

#endif
