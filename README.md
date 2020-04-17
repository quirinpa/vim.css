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

# Use it in your project

Copy and paste this to a terminal to get started using vim.css.

```sh
cd ~
git clone git@github.com:quirinpa/vim.css.git
cd $MY_PROJECT_ROOT
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
vss-path := \${HOME}/vss
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

# Commands

This is under construction
