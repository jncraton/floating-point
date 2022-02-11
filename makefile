all: fp

fp: fp.c
	gcc fp.c -Wall -Wextra -Wlogical-not-parentheses -Wno-unused-parameter -lm -o fp

test: fp
	./fp

clean:
	rm -f fp
