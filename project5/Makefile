main:	main.o ppm.o scanner.o
	cc -Wall -o main main.o ppm.o scanner.o

main.o: main.c scanner.h ppm.h
	gcc -Wall -c main.c

scanner.o:	scanner.c scanner.h
	gcc -Wall -c scanner.c

ppm.o:	ppm.c	ppm.h
	gcc -Wall -c ppm.c

clean:
	rm -f *.o