#
# Makefile
#
# week 3 section
# fall 2013
#

all: find generate

find: find.c binary.c bubble.c selection.c helpers.h
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o find find.c binary.c bubble.c selection.c -lcs50 -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core find generate
