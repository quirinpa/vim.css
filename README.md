# Description

This is a css framework that uses some concepts I've learned from the VIM editor.

I find that just like in VIM, once you understand it, it speeds up development and improves the result.

If you don't mind using make (POSIX) in your project, you can change configuration.

Otherwise you can just download a pre-configured vim.css.

# Example markup

Consider the following example index.html.

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<link rel="stylesheet" type="text/css" href="vim.css">
	</head>
	<body class="v0 f cblack sfv">
		<header class="h c p">
			<a class="round cgrey p tl" href="help.txt">?</a>
			<h1>vim.css example</h1>
		</header>
		<main class="v fg p cwhite">
			<div>
				My parent grows to fill the remaining
				space of the screen.
			</div>
			<div>
				I have 16px separations from my siblings
				and we are rendered vertically in regards
				to each other.
			</div>
			<div class="hs">
				<span class="tb">We are rendered horizontally</span>
				<span>And have 8px separations</span>
			</div>
		</main>
	</body>
</html>
```

Produces:

![Example screenshot](https://raw.githubusercontent.com/quirinpa/vim.css/master/example.png)

# Example configuration

Imagine you clone this repo to your home folder:
```sh
cd ~
git clone git@github.com:quirinpa/vim.css.git
```

Then, in your project root (copy and paste):
```sh
mkdir vss
cat - > vss/vss.config.h <<!
#define CONFIG_IPH 12px
#define CONFIG_ROUND
#include "vss.h"
CALL(TEXT_SIZE, TS)
CALL(BG_COLOR, CS)
CALL(COLOR, CS)
CALL(BO_COLOR, CS)
CALL(SIZE, SS)
CALL(PADDING, SS)
CALL(HORIZONTAL, SS)
CALL(VERTICAL, SS)
CALL(FLEX_VERTICAL, SS)
CALL(ROUND_T, SS)
ROUND_PADDING( , l)
main { color: C_black !important; }
!
cat - > vss/Makefile <<!
srcdir := .
vss-path := \${HOME}/vim.css
vss-t-args := -a0.112 -b-0.61 -c3.9 -d6.1 -m0.88
include \${vss-path}/vss.mk
!
cat - > vss/c.txt <<!
pri cyan
xlgrey #eee
grey grey
white white
black black
lgrey #aaa
red red
!
printf "/vss/t.h\n/vss/c.h" >> .gitignore
printf "vss:\n\t\${MAKE} -C \$@\n.PHONY: vss\n" > Makefile
```

Hitting "make" on your project root would create /vim.css, then you just need include it in your html.

# Key Concepts

**Commands** are usually the first letter of many of the classes of vim.css.
They specify the category upon which to act, or what to do.
Commands may have two letters. In this case they also specify the operation to perform.
There are exemptions, commands of a single letter that perform operations, and ones
that are meant to be combined with others.

**Command parameters** use labels to specify values for commands.

If you omit a parameter either a default value is used, or all values are assumed.

The following sections are separated by category. The titles of their sub-sections
are usually gcc preprocessor macros. They receive parameters as arguments and generate
commands:
> .like.this\<parameter\>

You don't have to know all the commands, knowing only a few can go a long way.

On to the details.

# Text

Text sizes are a parameter. They are generated using a third degree polynomial:

![3 polynomial](https://render.githubusercontent.com/render/math?math=y%3Da%2Ax%5E3%2Bb%2Ax%5E2%2Bc%2Ax%2Bd.)

Where x = i * m, where i is the index of the font size.

The following labels apply to font sizes (for now, this is not customizable):
```h
#define TS xs, s, , m, ml, l, xl, xxl, Xl, xXl, Xxl, XXl, L
```

If you look above you see a line like such, in vss's Makefile:
```make
vss-t-args := -a0.112 -b-0.61 -c3.9 -d6.1 -m0.88
```

This allows you to customize these values.

## TEXT\_SIZE(\<text size\>)
> .t\<text size\>

> .th\<text size\>

If you look at the example index.html, you can see round thing also has a "tl" class.
This means that this text results in the size corresponding to the l label. l is indexed 5 in TS.
And so x would be m * 5. In this example, y would eventually result in the font size of 38.5px.

The th command sets line height.

## ROUND\_T(\<text size\>)
> .t\<text size\>.round

Say we wanted an element that is round and that features a single character, of the size specified.
This is possible using this macro, as long there is no extra padding (for that, there is ROUND\_PADDING).

## bold levels
> .tb\<bold level\>

The tb command sets the bold level of an element. Bold levels' labels are:

xXs, Xs, xxs, xs, s, , xl, xxl, Xl

The corresponding values are:

100, 200, 300, 400, 500, 600, 700, 800 and 900

So an element with the "tb" class would have bold text and "txs" would have regular weighted text.

# Colors
Colors are generated based on the configuration file /vss/c.txt.

## COLOR(\<color\>)
> .C\<color\>

Sets an element's color to the one specified.

## BG\_COLOR(\<color\>)
> .c\<color\>

Sets an element's background color to the one specified.

## BO\_COLOR(\<color\>)
> .B\<direction\>\<color\>

Sets the border to the specified color.

**Direction** is specified using:

H, J, K, L

Which means left, bottom, top and right, just like in VIM.

If you don't specify a direction, then all directions are assumed.

# Size
Size uses the formula:

![2^x](https://render.githubusercontent.com/render/math?math=y%3D2%5E{x%2B1}.)

Where x is the index of the label intended, of the possible:

xxs, xs, s, , m, l, xl, xxl, Xl

Which correspond to:

2, 4, 8, 16, 24, 32, 64, 128 and 256.

## SIZE(\<size\>)
> .s\<direction\>\<axis\>\<size\>

**Direction** in this case is used to indicate minimum (J) and maximum (K) sizes in that axis.

**Axis** might be horizontal (h) or vertical (v). This parameter is the only one that is required.

**Size** may additionally be 100% (f) or 100% of the view in that axis (fv).

## PADDING(\<size\>)
> .p\<direction/axis\>\<size\>

Adds padding to an element.

## ABS\_PADDING(\<size\>)
> .rel.p\<axis/direction\>\<size\> \> .abs.\<direction\>

Positions an element close to the edge of the parent element in the
specified direction, taking into consideration the size of it's padding.

## CENTER\_ABS\_V(\<size\>)
> .abs.sv\<size\>

Vertically centers an absolutely positioned element of known size.

## CENTER\_ABS\_VP(\<size\>,\<paddingK\>,\<paddingJ\>)
> .pK\<paddingK\>.pJ\<paddingJ\> > .abs.sv\<size\>

Vertically centers an absolutely positioned element of known size, inside
an element with the specified padding.

## TABLE\_PADDING(\<size\>)

WIP

## MARGIN(\<size\>)
> .m\<direction\>\<size\>

Margins are **not recommended**. In my experience, using "v", "h" usually works,
and it produces markup that is easier to read (less specific stuff).

# Alignment

## HORIZONTAL(\<size\>)
> .h\<size\>

This makes it so that an element's children are displayed horizontally, separated
by the size specified.

## VERTICAL(\<size\>)
> .v\<size\>

The same, but for displaying children vertically.

The size may aditionally be "0".

## SPLIT\_HORIZONTAL(\<size\>)
> .x.h\<size\>

Indicates that an "h" element should be split in half.

## WRAP(\<size\>)
> .w\<size\>

Flex-wrap version of "h".

Props to mister Rubens Almeida for coming up with the first version.

## Others
> .f

Combine with "h" and "v" to indicate a flex element with those caracteristics.

> .c

Combine with "h" and optionally "f" to center vertically.

> .fg

Indicates that a child of a flex element should grow.

> .fgc

Indicates that all children of the flex element should grow.

# Round

You can add the .round class to make an element round.

Discussed here is also the "r" command which also relates to border radius.

## ROUND\_T(\<text size\>)
> .round.t\<text size\>

Adds support for round things that have a single character of the specified size.

## ROUND\_PADDING(\<padding size\>, \<text size\>)
> .p\<padding size\>.round.t\<text size\>

The same as above but taking padding into account.

## ROUND\_EDGE(\<size\>)
> .r\<direction\>\<size\>

Sets the border radius of the element in the specified direction.

You can combine vertical and horizontal directions (in that order), or omit it completely, as you would expect.

# Utility

## HOVER\_SHADOW(\<selector\>,\<shadow\>,\<ease\>,\<other\>)

Add properties to a selector so that it displays a growing shadow on hover
using the ::after pseudo-selector as described here:

![Fast box shadow](https://tobiasahlin.com/blog/how-to-animate-box-shadow/)
