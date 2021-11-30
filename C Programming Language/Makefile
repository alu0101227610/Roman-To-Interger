main: main.c romans.o
	gcc -g -o main main.c romans.o

romans.o: romans.h romans.c
	gcc -c romans.c

.PHONY: clean

clean:
	rm -f romans.o main