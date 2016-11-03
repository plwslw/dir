dir: dir.c
	gcc -o dir dir.c

run: dir
	./dir
