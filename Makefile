main: main.o
	gcc main.o -o main
main.o: main.c lib/core.h lib/Cronista.h lib/participante.h lib/users.h
	gcc -c $(ojbs)

clean:

	del main.o