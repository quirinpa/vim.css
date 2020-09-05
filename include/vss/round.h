#ifndef ROUND_H
#define ROUND_H

.round {
	text-align: center;
	border-radius: 50%;
	vertical-align: middle;
	display: inline-block;
	box-sizing: border-box;
}

#define ROUND_PADDING(_p, _t) \
	.p ## _p.round.t ## _t { \
		line-height: T_ ## _t; \
		width: calc(T_ ## _t + 2 * S_ ## _p); \
	}

#define ROUND_T(_t) \
	.round.t ## _t { \
		line-height: T_ ## _t; \
		width: calc(T_ ## _t); \
	}

#define ROUND_EDGE(_s) \
	.r ## _s { border-radius: S_ ## _s; } \
	\
	.rh ## _s { border-top-left-radius: S_ ## _s; border-bottom-left-radius: S_ ## _s; } \
	.rj ## _s { border-bottom-left-radius: S_ ## _s; border-bottom-right-radius: S_ ## _s; } \
	.rk ## _s { border-top-left-radius: S_ ## _s; border-top-right-radius: S_ ## _s; } \
	.rl ## _s { border-bottom-right-radius: S_ ## _s; border-top-right-radius: S_ ## _s; } \
	\
	.rjh ## _s { border-bottom-left-radius: S_ ## _s; } \
	.rjl ## _s { border-bottom-right-radius: S_ ## _s; } \
	.rkh ## _s { border-top-left-radius: S_ ## _s; } \
	.rkl ## _s { border-top-right-radius: S_ ## _s; }

#define ROUND_EDGE_PADDING(_s) \
	.rp ## _s { padding: calc(RP(_s)); } \
	.rpk ## _s { padding-top: calc(RP(_s)) !important; } \
	.rpj ## _s { padding-bottom: calc(RP(_s)) !important; } \
	.rph ## _s { padding-left: calc(RP(_s)) !important; } \
	.rpl ## _s { padding-right: calc(RP(_s)) !important; } \

#endif
