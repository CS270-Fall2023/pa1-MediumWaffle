#makros
C= gcc
FLAGS= -Wall -c -g

clean:
	rm -r *.o test

all: test

test: main.o pa1.o pa1.h
	$(C) main.o pa1.o -o test

main.o: main.c pa1.h
	$(C) $(FLAGS) main.c

pa1.o: pa1.c pa1.h
	$(C) $(FLAGS) pa1.c