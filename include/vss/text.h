#ifndef TEXT_H
#define TEXT_H

#define TEXT_SIZE(_t) \
	 .ts ## _t { font-size: T_ ## _t; } \
	 .th ## _t { line-height: T_ ## _t; }

#define COLOR(_c) \
	.cf ## _c { color: C_ ## _c !important; }

#define BG_COLOR(_c) \
	.c ## _c { background-color: C_ ## _c; }

#define BO_COLOR(_c) \
	.b ## _c { border: solid thin C_ ## _c; } \
	.bh ## _c { border-left: solid thin C_ ## _c; } \
	.bj ## _c { border-bottom: solid thin C_ ## _c; } \
	.bk ## _c { border-top: solid thin C_ ## _c; } \
	.bl ## _c { border-right: solid thin C_ ## _c; }

.ct { background-color: transparent !important; }
.tal { text-align: left !important; }
.tac { text-align: center !important; }
.tar { text-align: right !important; }
.tuc { text-transform: uppercase; }
.vak { vertical-align: top; }

.tbxss { font-weight: 100; } /* thin */
.tbss { font-weight: 200; } /* extra-light */
.tbxxs { font-weight: 300; } /* light */
.tbxs { font-weight: 400; } /* regular */
.tbs { font-weight: 500; } /* medium */
.tb { font-weight: 600; } /* semi-bold */
.tbxl { font-weight: 700; } /* bold */
.tbxxl { font-weight: 800; } /* extra-bold */
.tbll { font-weight: 900; } /* black */

.tnow { white-space: nowrap; }

#endif
