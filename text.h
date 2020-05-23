#ifndef TEXT_H
#define TEXT_H

#define TEXT_SIZE(_t) \
	 .t ## _t { font-size: T_ ## _t; } \
	 .th ## _t { line-height: T_ ## _t; }

#define COLOR(_c) \
	.cf ## _c { color: C_ ## _c !important; }

#define BG_COLOR(_c) \
	.c ## _c { background-color: C_ ## _c; }

#define BO_COLOR(_c) \
	.B ## _c { border: solid thin C_ ## _c; } \
	.BH ## _c { border-left: solid thin C_ ## _c; } \
	.BJ ## _c { border-bottom: solid thin C_ ## _c; } \
	.BK ## _c { border-top: solid thin C_ ## _c; } \
	.BL ## _c { border-right: solid thin C_ ## _c; }

.ct { background-color: transparent !important; }
.tal { text-align: left !important; }
.tac { text-align: center !important; }
.tar { text-align: right !important; }
.tuc { text-transform: uppercase; }
.vaK { vertical-align: top; }

.tbxXs { font-weight: 100; }
.tbXs { font-weight: 200; }
.tbxxs { font-weight: 300; }
.tbxs { font-weight: 400; } /* regular (in this case?) */
.tbs { font-weight: 500; }
.tb { font-weight: 600; }
.tbxl { font-weight: 700; }
.tbxxl { font-weight: 800; }
.tbXl { font-weight: 900; }

.tnow { white-space: nowrap; }

#endif
