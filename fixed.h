#ifndef FIXED_H
#define FIXED_H

#define FIXED_MAIN(_s) min-height: calc(100vh - H_ ## _s); margin-top: H_ ## _s;

#define FIXED(_s) \
	.F._ ## _s header { height: H_ ## _s; } \
	.F._ ## _s main { FIXED_MAIN(_s); }

.F { background-color: C_pri; }
.F header {
	height: H_;
	position: fixed;
	top: 0;
	z-index: 2;
	background-color: C_pri;
}
.F main {
	FIXED_MAIN();
	padding: calc(RP(xl));
	padding-top: calc(S_xl);
	padding-bottom: calc(BH(xl) + RP(xl));
	border-radius: S_xl 0 0;
}
.F main, .F header { width: 100%; }

.rpK {
	padding-top: calc(RP(xl)) !important;
	/* padding-bottom: calc(BH(xl) + RP(xl)); */
}

#endif
