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
		<link rel="stylesheet" type="text/css" href="vim.css">
	</head>
	<body class="v f p cpri sfv">
		<header class="h c">
			<a class="round cred p tl" href="help.txt">?</a>
			<span>vim.css example</span>
		</header>
		<main class="v fg cwhite">
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
				<span>We are rendered horizontally<span>
				<span>And have 8px separations<span>
			</div>
		</main>
	</body>
</html>
```

Renders as:
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
CALL(ROUND_T, SS)
!
cat - > vss/Makefile <<!
srcdir := .
vss-path := ${HOME}/vss # for example
vss-out := ../vim.css
vss-t-args := -a0.113 -b-0.6 -c4 -d6 -m0.87
include ${vss-path}/vss.mk
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
cat - > Makefile <<!
vss:
	${MAKE} -C $@
.PHONY: vss
!
```

Hit "make" on your project root to prepare vim.css, and then just include it in your html.

# Commands

This is under construction
