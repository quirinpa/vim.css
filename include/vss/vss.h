#include "utils.h"

#include "text-size.h"
#include "size.h"
#include "color.h"
#include "div.h"

#define LB_ROUND round
#define LB_SIZE s
#define LB_TEXT t
#define LB_FONT_WEIGHT NC(LB_TEXT, b)
#define LB_TEXT_ALIGN NC(LB_TEXT, a)
#define LB_FONT_SIZE NC(LB_TEXT, s)
#define LB_LINE_HEIGHT NC(LB_TEXT, h)
#define LB_TEXT_TRANSFORM NC(LB_TEXT, t)
#define LB_TEXT_OVERFLOW NC(LB_TEXT, o)
#define LB_POSITION a
#define LB_PADDING p
#define LB_TABLE tbl
#define LB_TABLE_PADDING NC(LB_TABLE, LB_PADDING)
#define LB_TABLE_LAYOUT LB_TABLE
#define LB_SPLIT x
#define LB_MARGIN m
#define LB_OUTLINE ou
#define LB_BORDER bo
#define LB_COLOR cf
#define LB_BACKGROUND_COLOR c
#define LB_BORDER_RADIUS r
#define LB_FLEX f
#define LB_FLEX_WRAP fw
#define LB_FLEX_ALIGN_ITEMS fi
#define LB_FLEX_JUSTIFY_CONTENT fc
#define LB_FLEX_ALIGN_SELF fa
#define LB_FLEX_GROW NC(LB_FLEX, g)
#define LB_FLEX_GROW_CHILDREN NC(LB_FLEX_GROW, c)
#define LB_OVERFLOW o
#define LB_FULL f
#define LB_VIEW v
#define LB_stretch s
#define LB_space_between sb
#define LB_center c
#define LB_absolute abs
#define LB_fixed fix
#define LB_relative rel
#define LB_auto a
#define LB_hidden h
#define LB_ellipsis e
#define LB_vertical v

#ifdef CONFIG_VANILLA
#define LB_horizontal _
#define LB_left h
#define LB_right l
#define LB_top k
#define LB_bottom j
#else
#define LB_horizontal h
#define LB_left l
#define LB_right r
#define LB_top t
#define LB_bottom b
#endif

/* #define LB(of) NC(LB_, of) */
#define VAL(TYPE, LABEL) NC(VAL_, TYPE, _, LABEL)
#define RP(_s) (VAL_SIZE(_s) / PI)

#define TEXT_SIZE(_t) \
	 .NC(LB_FONT_SIZE, _t) { font-size: VAL(TEXT_SIZE, _t) !important; } \
	 .NC(LB_LINE_HEIGHT, _t) { line-height: VAL(TEXT_SIZE, _t); }

#define COLOR(_c) \
	.NC(LB_COLOR, _c) { color: VAL(COLOR, _c) !important; }

#define BACKGROUND_COLOR(_c) \
	.NC(LB_BACKGROUND_COLOR, _c) { background-color: VAL(COLOR, _c) !important; }

#define OUTLINE(_c) \
	.NC(LB_OUTLINE, _c) { outline: solid thin VAL(COLOR, _c); }

#define BORDER(_c) \
	.NC(LB_BORDER, _c) { border: solid thin VAL(COLOR, _c); }

#define BORDER_DIR(DIRE, _c) \
	.NC(LB_BORDER, NC(LB_, DIRE), _c) { border-DIRE: solid thin VAL(COLOR, _c); }

#define ALL_BORDER(_c) \
	BORDER(_c) \
	BORDER_DIR(left, _c) \
	BORDER_DIR(bottom, _c) \
	BORDER_DIR(top, _c) \
	BORDER_DIR(right, _c)

#define HEIGHT(VALUE) \
	.NC(LB_SIZE, LB_vertical, NC(LB_, VALUE)) { height: VAL(SIZE, VALUE) !important; }

#define MIN_WIDTH(VALUE) \
	.NC(LB_SIZE, LB_bottom, LB_horizontal, NC(LB_, VALUE)) { min-width: VAL(SIZE, VALUE) !important; }
	
#define SIZE(_s) \
	.NC(LB_SIZE, LB_vertical, _s), .NC(LB_SIZE, _s) { height: VAL(SIZE, _s); } \
	.NC(LB_SIZE, LB_horizontal, _s), .NC(LB_SIZE, _s) { width: VAL(SIZE, _s); } \
	.NC(LB_SIZE, LB_top, LB_horizontal, _s) { max-width: VAL(SIZE, _s); } \
	.NC(LB_SIZE, LB_top, LB_vertical, _s) { max-height: VAL(SIZE, _s); }

#define PADDING(_s) \
	.NC(LB_PADDING, _s) { padding: VAL(SIZE, _s) !important; }

#define PADDING_DIR(DIRE, _s) \
	.NC(LB_PADDING, NC(LB_, DIRE), _s) { padding-DIRE: VAL(SIZE, _s); } \

#define ALL_PADDING(_s) \
	PADDING(_s) \
	.NC(LB_PADDING, LB_horizontal, _s) { padding-left: VAL(SIZE, _s); padding-right: VAL(SIZE, _s); } \
	.NC(LB_PADDING, LB_vertical, _s) { padding-top: VAL(SIZE, _s); padding-bottom: VAL(SIZE, _s); } \
	PADDING_DIR(left, _s) \
	PADDING_DIR(bottom, _s) \
	PADDING_DIR(top, _s) \
	PADDING_DIR(right, _s)

#define PAD_POS_DIR(DIRE, _s) \
	.NC(LB_PADDING, _s) > .NC(LB_POSITION, NC(LB_, DIRE)) { DIRE: VAL(SIZE, _s); }

#define PAD_AXIS_DIR(AXIS, DIRE, _s) \
	.NC(LB_PADDING, NC(LB_, AXIS), _s) > .NC(LB_POSITION, NC(LB_, DIRE)) { DIRE: VAL(SIZE, _s); }

#define PAD_DIR_POS_DIR(DIRE, _s) \
	PAD_AXIS_DIR(DIRE, DIRE, _s)

#define ABS_PADDING(_s) \
	PAD_AXIS_DIR(horizontal, left, _s) \
	PAD_AXIS_DIR(vertical, bottom, _s) \
	PAD_AXIS_DIR(vertical, top, _s) \
	PAD_AXIS_DIR(horizontal, right, _s) \
	.NC(LB_PADDING, LB_horizontal, _s) > .s_f { width: calc(100% - VAL(SIZE, _s) * 2); } \
	\
	PAD_POS_DIR(left, _s) \
	PAD_POS_DIR(bottom, _s) \
	PAD_POS_DIR(top, _s) \
	PAD_POS_DIR(right, _s) \
	.NC(LB_PADDING, _s) > .s_f { width: calc(100% - VAL(SIZE, _s) * 2); } \
	\
	PAD_DIR_POS_DIR(left, _s) \
	PAD_DIR_POS_DIR(bottom, _s) \
	PAD_DIR_POS_DIR(top, _s) \
	PAD_DIR_POS_DIR(right, _s)

#define CENTER_vertical(_s) \
	.LB_ABSOLUTE.LB_SIZE ## _s, .LB_ABSOLUTE.NC(LB_SIZE, LB_vertical, _s) { top: calc(50% - VAL(SIZE, _s) / 2); }

#define PAD_CENTER_vertical(_pK, _pJ, _s) \
	.NC(LB_PADDING, LB_TOP, _pK).NC(LB_PADDING, LB_BOTTOM, _pJ) > .LB_ABSOLUTE.LB_SIZE ## _s { top: calc((100% - VAL(SIZE, _s) + VAL(SIZE, _pK) - VAL(SIZE, _pJ)) / 2); }

#define TABLE_PADDING(_s) \
	table.NC(LB_TABLE_PADDING, _s) > tbody > tr > td { padding: calc(VAL(SIZE, _s) / 2); } \
	table.NC(LB_TABLE_PADDING, _s) th { padding-top: calc(VAL(SIZE, _s) / 2); padding-bottom: calc(VAL(SIZE, _s) / 2); } \
	table.NC(LB_TABLE_PADDING, _s) > tbody > tr > td:first-child { padding-left: VAL(SIZE, _s); } \
	table.NC(LB_TABLE_PADDING, _s) > tbody > tr > td:last-child { padding-right: VAL(SIZE, _s); } \
	table.NC(LB_TABLE_PADDING, _s) > tbody > tr > td { padding: VAL(SIZE, _s) calc(VAL(SIZE, _s) / 2); }

#define MARGIN_DIR(DIRE, _s) \
	.NC(LB_MARGIN, NC(LB_, DIRE), _s) { margin-DIRE: VAL(SIZE, _s) !important; }

#define MARGIN(_s) \
	MARGIN_DIR(left, _s) \
	MARGIN_DIR(bottom, _s) \
	MARGIN_DIR(top, _s) \
	MARGIN_DIR(right, _s)

#define DIVN(AXIS, _d) \
	.NC(LB_SPLIT, NC(LB_, AXIS), _d).NC(NC(LB_, AXIS), 0) > * { \
		width: calc(100% / _d); \
	}

#define DIV(AXIS, _s, _d) \
	.NC(LB_SPLIT, NC(NC(LB_, AXIS), _d)).NC(NC(LB_, AXIS), _s) > * { \
		width: calc((100% - VAL(SIZE, _s) * (_d - 1)) / _d); \
	}

#ifdef VSS_DIV
#define ALL_DIV(AXIS, _s) CALL1(NC(DIV_, AXIS), _s, ALL_DIVS)
#else
#define ALL_DIV(AXIS, _s)
#endif

#define DIV_horizontal(_s, _d) DIV(horizontal, _s, _d)
#define DIV_vertical(_s, _d) DIV(vertical, _s, _d)

#define AXIS(AXIS, _s) NC(AXIS_, AXIS)(_s)
#define ALL_AXIS(_s) AXIS_horizontal(_s) AXIS_vertical(_s)

/* ._ ## _s:not(.f) > :not(.f) { display: inline-block; } \ */
#ifndef VSS_NO_FLEX
#define AXIS_horizontal(_s) \
	.NC(LB_horizontal, _s):not(.LB_FLEX) > * { margin-left: VAL(SIZE, _s); } \
	.NC(LB_horizontal, _s):not(.LB_FLEX) > :first-child { margin-left: 0; } \
	.NC(LB_horizontal, _s):not(.LB_FLEX) { overflow: hidden } \
	.NC(LB_horizontal, _s):not(.LB_FLEX) > :not(.LB_FLEX):not(table) { display: block; } \
	.NC(LB_horizontal, _s):not(.LB_FLEX) > :not(.LB_FLEX) { float: left; } \
	.NC(LB_horizontal, _s) > .LB_FLEX { display: inline-flex; } \
	.NC(LB_horizontal, _s).LB_FLEX { column-gap: VAL(SIZE, _s); } \
	.NC(LB_horizontal, _s).LB_FLEX > * { margin: 0; } \
	ALL_DIV(horizontal, _s)

#define AXIS_vertical(_s) \
	.NC(LB_vertical, _s):not(.LB_FLEX) > * { margin-top: VAL(SIZE, _s); } \
	.NC(LB_vertical, _s):not(.LB_FLEX) > :first-child { margin-top: 0; } \
	.NC(LB_vertical, _s).LB_FLEX { row-gap: VAL(SIZE, _s); } \
	.NC(LB_vertical, _s).LB_FLEX:not(.LB_FLEX_WRAP) { flex-direction: column; } \
	.NC(LB_vertical, _s).LB_FLEX > * { margin: 0; } \
	ALL_DIV(vertical, _s)
#else
#warn VSS_NO_FLEX is defined. css will be incompatible with standard versions
#define AXIS_horizontal(_s) \
	.NC(LB_horizontal, _s) > * { margin-left: VAL(SIZE, _s); } \
	.NC(LB_horizontal, _s) > :first-child { margin-left: 0; } \
	.NC(LB_horizontal, _s) { overflow: hidden } \
	.NC(LB_horizontal, _s) > * { display: block; float: left; } \
	ALL_DIV(horizontal, _s)

#define AXIS_vertical(_s) \
	.NC(LB_vertical, _s) > * { margin-top: VAL(SIZE, _s); } \
	.NC(LB_vertical, _s) > :first-child { margin-top: 0; } \
	ALL_DIV(vertical, _s)
#endif

#define TABLE_VERTICAL(_s) \
	table.NC(LB_vertical, _s) { border-spacing: 0 VAL(SIZE, _s); border-collapse: separate; } \
	table.NC(LB_vertical, _s) > * { margin_top: 0; }

#define ROUND_PADDING(_p, _t) \
	.NC(LB_PADDING, _p).LB_ROUND.NC(LB_FONT_SIZE, _t) { \
		line-height: VAL(TEXT_SIZE, _t); \
		width: calc(VAL(TEXT_SIZE, _t) + 2 * VAL(SIZE, _p)); \
	}

#define ROUND_T(_t) \
	.LB_ROUND.NC(LB_FONT_SIZE, _t) { \
		line-height: VAL(TEXT_SIZE, _t); \
		width: VAL(TEXT_SIZE, _t); \
	}

#define ROUND_EDGE(_s) \
	.NC(LB_BORDER_RADIUS, _s) { border-radius: VAL(SIZE, _s); } \
	\
	.NC(LB_BORDER_RADIUS, LB_left, _s) { border-top-left-radius: VAL(SIZE, _s); border-bottom-left-radius: VAL(SIZE, _s); } \
	.NC(LB_BORDER_RADIUS, LB_bottom, _s) { border-bottom-left-radius: VAL(SIZE, _s); border-bottom-right-radius: VAL(SIZE, _s); } \
	.NC(LB_BORDER_RADIUS, LB_top, _s) { border-top-left-radius: VAL(SIZE, _s); border-top-right-radius: VAL(SIZE, _s); } \
	.NC(LB_BORDER_RADIUS, LB_right, _s) { border-bottom-right-radius: VAL(SIZE, _s); border-top-right-radius: VAL(SIZE, _s); } \
	\
	.NC(LB_BORDER_RADIUS, LB_bottom, LB_left, _s) { border-bottom-left-radius: VAL(SIZE, _s); } \
	.NC(LB_BORDER_RADIUS, LB_bottom, LB_right, _s) { border-bottom-right-radius: VAL(SIZE, _s); } \
	.NC(LB_BORDER_RADIUS, LB_top, LB_left, _s) { border-top-left-radius: VAL(SIZE, _s); } \
	.NC(LB_BORDER_RADIUS, LB_top, LB_right, _s) { border-top-right-radius: VAL(SIZE, _s); }

#define ROUND_EDGE_PADDING(_s) \
	.rp ## _s { padding: calc(RP(_s)); } \
	.rpk ## _s { padding-top: calc(RP(_s)) !important; } \
	.rpj ## _s { padding-bottom: calc(RP(_s)) !important; } \
	.rph ## _s { padding-left: calc(RP(_s)) !important; } \
	.rpl ## _s { padding-right: calc(RP(_s)) !important; } \

#define TEXT_ALIGN(DIRE) \
	.NC(LB_TEXT_ALIGN, NC(LB_, DIRE)) { text-align: DIRE !important; }

#define VAL_FONT_WEIGHT_thin 100
#define VAL_FONT_WEIGHT_extra_light 200
#define VAL_FONT_WEIGHT_light 300
#define VAL_FONT_WEIGHT_regular 400
#define VAL_FONT_WEIGHT_medium 500
#define VAL_FONT_WEIGHT_semi_bold 600
#define VAL_FONT_WEIGHT_bold 700
#define VAL_FONT_WEIGHT_extra_bold 800
#define VAL_FONT_WEIGHT_black 900

#define LB_FONT_WEIGHT_thin thin
#define LB_FONT_WEIGHT_extra_light extra_light
#define LB_FONT_WEIGHT_light light
#define LB_FONT_WEIGHT_regular regular
#define LB_FONT_WEIGHT_medium medium
#define LB_FONT_WEIGHT_semi_bold semi_bold
#define LB_FONT_WEIGHT_bold bold
#define LB_FONT_WEIGHT_extra_bold extra_bold
#define LB_FONT_WEIGHT_black black

#define BASE_FONT_WEIGHTS thin, regular, bold
#define ALL_FONT_WEIGHTS BASE_FONT_WEIGHTS, extra_light, light, medium, semi_bold, extra_bold, black

#define FONT_WEIGHT(WEIGHT) \
	.NC(LB_FONT_WEIGHT, NC(LB_FONT_WEIGHT_, WEIGHT)) { font-weight: VAL(FONT_WEIGHT, WEIGHT); }

#define FULL_SIZE_horizontal \
	.NC(LB_SIZE, LB_horizontal, LB_FULL) { width: 100%; } \

#define FULL_SIZE \
	.NC(LB_SIZE, LB_horizontal, LB_FULL, LB_VIEW) { width: 100vw; } \
	.NC(LB_SIZE, LB_vertical, LB_FULL, LB_VIEW) { height: 100vh; } \
	FULL_SIZE_horizontal \
	.NC(LB_SIZE, LB_vertical, LB_FULL) { height: 100%; } \
	.NC(LB_SIZE, LB_FULL) { width: 100%; height: 100%; } \
	.NC(LB_SIZE, LB_FULL, LB_VIEW) { width: 100vw; height: 100vh; }

#define FULL_SIZE_MIN_MAX \
	.NC(LB_SIZE, LB_top, LB_horizontal, LB_FULL) { max-width: 100%; } \
	.NC(LB_SIZE, LB_top, LB_vertical, LB_FULL) { max-height: 100%; } \
	.NC(LB_SIZE, LB_bottom, LB_horizontal, LB_FULL) { min-width: 100%; } \
	.NC(LB_SIZE, LB_bottom, LB_vertical, LB_FULL) { min-height: 100%; } \
	.NC(LB_SIZE, LB_top, LB_horizontal, LB_FULL, LB_VIEW) { max-width: 100vw; } \
	.NC(LB_SIZE, LB_top, LB_vertical, LB_FULL, LB_VIEW) { max-height: 100vh; } \
	.NC(LB_SIZE, LB_bottom, LB_horizontal, LB_FULL, LB_VIEW) { min-width: 100vw; } \
	.NC(LB_SIZE, LB_bottom, LB_vertical, LB_FULL, LB_VIEW) { min-height: 100vh; }

#define FLEX \
	.LB_FLEX { display: flex; } \
	.LB_FLEX_WRAP { flex-wrap: wrap; } \

#define VAL_ALIGN_ITEMS_center center
#define VAL_ALIGN_ITEMS_stretch stretch
#define VAL_ALIGN_ITEMS_top flex-start
#define VAL_ALIGN_ITEMS_bottom flex-end

#define ALL_ALIGN_ITEMS center, stretch, top, bottom

#define ALIGN_ITEMS(VALUE) \
	.NC(LB_FLEX_ALIGN_ITEMS, NC(LB_, VALUE)) { align-items: VAL(ALIGN_ITEMS, VALUE); }

#define VAL_JUSTIFY_CONTENT_center center
#define VAL_JUSTIFY_CONTENT_top flex-start
#define VAL_JUSTIFY_CONTENT_bottom flex-end
#define VAL_JUSTIFY_CONTENT_space_between space-between

#define JUSTIFY_CONTENT(VALUE) \
	.NC(LB_FLEX_JUSTIFY_CONTENT, NC(LB_, VALUE)) { justify-content: VAL(JUSTIFY_CONTENT, VALUE); }

#define ALL_JUSTIFY_CONTENT center, top, bottom, space_between

#define VAL_ALIGN_SELF_top flex-start
#define VAL_ALIGN_SELF_bottom flex-end
#define VAL_ALIGN_SELF_center center

#define ALL_ALIGN_SELF top, bottom, center

#define ALIGN_SELF(VALUE) \
	.NC(LB_FLEX_ALIGN_SELF, NC(LB_, VALUE)) { align-self: VAL(ALIGN_SELF, VALUE); }

#define ALL_FLEX \
	FLEX \
	.LB_FLEX_GROW { flex-grow: 1; } \
	.LB_FLEX_GROW- { flex-grow: 0 !important; } \
	.LB_FLEX_GROW_CHILDREN > * { flex-grow: 1; } \
	CALL(ALIGN_ITEMS, ALL_ALIGN_ITEMS) \
	CALL(JUSTIFY_CONTENT, ALL_JUSTIFY_CONTENT) \
	CALL(ALIGN_SELF, ALL_ALIGN_SELF) \
	.tcv { \
		display: inline-flex !important; \
		flex-direction: column; \
		justify-content: center; \
		text-align: center; \
	}

#define AXIS_0 \
	.NC(LB_horizontal, 0):not(.f) > :not(.f) { display: inline-block; } \
	.NC(LB_horizontal, 0) > .f { display: inline-flex; } \
	.LB_FLEX.NC(LB_vertical, 0):not(.fw) { flex-direction: column; }

#define POSITION(POS) \
	.NC(LB_, POS) { position: POS; }

#define DIRE(DIRE) \
	.NC(LB_POSITION, NC(LB_, DIRE)) { DIRE: 0; }

#define ROUND \
	.LB_ROUND { \
		text-align: center; \
		border-radius: 50%; \
		vertical-align: middle; \
		display: inline-block; \
		box-sizing: border-box; \
	}

#define OVERFLOW(OVERFLOW) \
	.NC(LB_OVERFLOW, NC(LB_, OVERFLOW)) { overflow: OVERFLOW; }

#define TEXT_OVERFLOW(OVERFLOW) \
	.NC(LB_TEXT_OVERFLOW, NC(LB_, OVERFLOW)) { text-overflow: OVERFLOW; }

#define LB_TABLE_LAYOUT_fixed f
#define VAL_TABLE_LAYOUT_fixed fixed

#define TABLE_LAYOUT(VALUE) \
	.NC(LB_TABLE_LAYOUT, NC(LB_TABLE_LAYOUT_, VALUE)) { table-layout: VALUE; }

#define LB_TEXT_TRANSFORM_uppercase uc
#define VAL_TEXT_TRANSFORM_uppercase uppercase

#define TEXT_TRANSFORM(VALUE) \
	.NC(LB_TEXT_TRANSFORM, NC(LB_TEXT_TRANSFORM_, VALUE)) { text-transform: VALUE; }

#if 0
label > input, label > textarea { display: block; }
input, textarea { padding: 6px CONFIG_IPH; }
button, a, *[ng-click] { cursor: pointer; user-select: none; }
body { margin: 0 }
table { width: 100%; }
#define HOVER_SHADOW(_selector, _shadow, _ease, _other) \
	_selector :: after { \
		box-shadow: _shadow; transition: opacity _ease; \
		position: absolute; left: 0; right: 0; top: 0; bottom: 0; \
		opacity: 0; content: ''; _other \
	} \
	_selector:hover::after { opacity: 1; }
button.LB_ROUND::after {
	border-radius: 50%;
}
HOVER_SHADOW(
	button:not(:disabled),
	0 5px 15px rgba(0, 0, 0, 0.3),
	0.3s ease-in-out,
	border-radius: S_s
)
.vak { vertical-align: top; }
.dn, script { display: none !important; }
.tnow { white-space: nowrap; }
:root {
	VARS(TEXT_SIZE, ALL_TEXT_SIZES)
	VARS(SIZE, ALL_SIZES)
	VARS(COLOR, ALL_COLORS)
	VARS(DIV, ALL_DIVS)
}
#endif
