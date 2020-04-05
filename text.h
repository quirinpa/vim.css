#ifndef TEXT_H
#define TEXT_H

#define DECLARE_T(_t) \
	 .t ## _t { font-size: T_ ## _t; }

#define DECLARE_C(_c) \
	.c ## _c { background-color: C_ ## _c; color: white; } \
	.C ## _c { color: C ## _c; }

DECLARE(T, TS)

.tal { text-align: left; }
.tac { text-align: center; }
.tar { text-align: right; }
.tuc { text-transform: uppercase; }
.tb { font-weight: bold; }
.tnow { white-space: nowrap; }

DECLARE(C, CS)

#endif
