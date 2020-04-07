#ifndef TEXT_H
#define TEXT_H

#define TEXT_SIZE(_t) \
	 .t ## _t { font-size: T_ ## _t; }

#define COLOR(_c) \
	.C ## _c { color: C_ ## _c; }

#define BG_COLOR(_c) \
	.c ## _c { background-color: C_ ## _c; color: white; }

#define BO_COLOR(_c) \
	.B ## _c { border: solid thin C_ ## _c; } \
	.BH ## _c { border-left: solid thin C_ ## _c; } \
	.BJ ## _c { border-bottom: solid thin C_ ## _c; } \
	.BK ## _c { border-top: solid thin C_ ## _c; } \
	.BL ## _c { border-right: solid thin C_ ## _c; }

.tal { text-align: left; }
.tac { text-align: center; }
.tar { text-align: right; }
.tuc { text-transform: uppercase; }

.tbxXs { font-weight: 100; }
.tbXs { font-weight: 300; }
.tbxxs { font-weight: 400; }
.tbxs { font-weight: 500; }
.tbs { font-weight: 600; }
.tb { font-weight: 700; }
.tbxl { font-weight: 800; }
.tbxxl { font-weight: 800; }
.tbXl { font-weight: 900; }

.tnow { white-space: nowrap; }

#endif
