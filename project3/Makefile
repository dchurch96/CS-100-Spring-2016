text:	text.o scanner.o
	gcc -Wall -o text text.o scanner.o

scanner.o:	scanner.c scanner.h
	gcc -Wall -c scanner.c

wash.o:	text.c	scanner.h
	gcc -Wall -c wash.c

clean:
	rm -f *.o text
