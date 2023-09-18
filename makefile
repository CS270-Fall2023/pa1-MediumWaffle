test: main.o pa1.o pa1.h
	gcc main.o pa1.o -o test

main.o: main.c pa1.h
	gcc -Wall -c -g main.c

pa1.o: pa1.c pa1.h
	gcc -Wall -c -g pa1.c

clean:
	rm -r *.o test