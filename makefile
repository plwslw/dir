dir: dir.c
	gcc -o dir dir.c -I

run: all
	./dir
