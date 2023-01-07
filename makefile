all: isort txtfind
isort: isort.c
	gcc isort.c -o isort
txtfind: txtfind.c
	gcc txtfind.c -o txtfind

clean:
	rm -f *.o isort	txtfind