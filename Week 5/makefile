all: prog

prog: bst.o compare.o
	gcc -g -Wall -std=c99 -o prog bst.o compare.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c
		
bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c

clean:	
	rm bst.o
	rm compare.o
	rm prog
