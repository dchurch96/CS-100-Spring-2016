main:	main.o game.o scanner.o
	cc -Wall -o main main.o game.o scanner.o

main.o: main.c scanner.h game.h
	gcc -Wall -c main.c

scanner.o:	scanner.c scanner.h
	gcc -Wall -c scanner.c

game.o:	game.c	game.h
	gcc -Wall -c game.c

clean:
	rm -f *.o