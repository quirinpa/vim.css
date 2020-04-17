# Description

This is a css framework that uses some concepts I've learned from the VIM editor.
If you don't mind using make (POSIX) in your project, you can change configuration,
otherwise you can download a pre-configured vim.css.

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

# Excample configuration

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

# Concepts

## Commands

## Text sizes

Text sizes are generated using a third degree polynomial:

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

### TEXT\_SIZE(\<text size\>)
> t\<text size\>
> th\<text size\>

If you look at the example index.html, you can see round thing also has a "tl" class.
This means that this text results in the size corresponding to the l label. l is indexed 5 in TS.
And so x would be m * 5. In this example, y would eventually result in the font size of 38.5px.

The th command sets line height.

### ROUND\_T(\<text size\>)
> t\<text size\>.round

Say we wanted an element that is round and that features a single character, of the size specified.
This is possible using this macro, as long there is no extra padding (for that, there is ROUND\_PADDING).

### bold levels
> tb\<bold level\>

The tb command sets the bold level of an element. Bold levels' labels are:

xXs, Xs, xxs, xs, s, , xl, xxl, Xl

The corresponding values are:

100, 200, 300, 400, 500, 600, 700, 800 and 900

So an element with the "tb" class would have bold text and "txs" would have regular weighted text.

## Colors
Colors are generated based on the configuration file /vim-css/c.txt.

### COLOR(\<color\>)
> .C\<color\>
Sets an element's color to the one specified.

### BG\_COLOR(\<color\>)
> .c\<color\>
Sets an element's background color to the one specified.

### BO\_COLOR(\<color\>)
> .B\<direction\>\<color\>
Sets the border to the specified color.

Direction is specified using:

H, J, K, L

Which means left, bottom, top and right, just like in VIM.
If you don't specify a direction, then all directions are assumed.l
