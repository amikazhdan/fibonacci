postfix: fibon.o list.o
	gcc fibon.o list.o -o postfix

fibon.o: fibon.c list.h
	gcc -c -ansi -pedantic -Wall -g fibon.c -o fibon.o

list.o: list.c list.h
	gcc -c -ansi -pedantic -Wall -g list.c -o list.o
