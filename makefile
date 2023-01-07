all: isort txtfind
isort: isort.c
	gcc -Wall isort.c -o isort
txtfind: txtfind.c
	gcc -Wall txtfind.c -o txtfind

clean:
	rm -f *.o isort	txtfind
