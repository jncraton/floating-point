all: fp

fp: fp.c
	gcc fp.c -Wall -Wextra -Wlogical-not-parentheses -lm -o fp
	./fp

clean:
	rm -f fp
