#ifndef ROUND_H
#define ROUND_H

.round {
	text-align: center;
	border-radius: 50%;
	vertical-align: middle;
	display: inline-block;
	box-sizing: border-box;
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

#define ROUND_T(_t) \
	round.t ## _t { \
		line-height: T_ ## _t; \
		width: calc(T_ ## _t); \
	}

#define ROUND_EDGE(_s) \
	.r ## _s { border-radius: S_ ## _s; } \
	\
	.rH ## _s { border-top-left-radius: S_ ## _s; border-bottom-left-radius: S_ ## _s; } \
	.rJ ## _s { border-bottom-left-radius: S_ ## _s; border-bottom-right-radius: S_ ## _s; } \
	.rK ## _s { border-top-left-radius: S_ ## _s; border-top-right-radius: S_ ## _s; } \
	.rL ## _s { border-bottom-right-radius: S_ ## _s; border-top-right-radius: S_ ## _s; } \
	\
	.rJH ## _s { border-bottom-left-radius: S_ ## _s; } \
	.rJL ## _s { border-bottom-right-radius: S_ ## _s; } \
	.rKH ## _s { border-top-left-radius: S_ ## _s; } \
	.rKL ## _s { border-top-right-radius: S_ ## _s; }

#define ROUND_EDGE_PADDING(_s) \
	.rp ## _s { padding: calc(RP(_s)); } \
	.rpK ## _s { padding-top: calc(RP(_s)) !important; } \
	.rpJ ## _s { padding-bottom: calc(RP(_s)) !important; } \
	.rpH ## _s { padding-left: calc(RP(_s)) !important; } \
	.rpL ## _s { padding-right: calc(RP(_s)) !important; } \

#endif
