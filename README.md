# Description

This is a css framework that uses some concepts I've learned from the VIM editor.
It shines the most for web projects built with make, but you can make it work for any project.

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

# Features / Commands

This is under construction
