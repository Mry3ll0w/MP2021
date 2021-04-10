
main: main.o core.o Cronista.o participante.o 
	gcc main.o lib/admin.h core.o Cronista.o participante.o -o main
	./main
	
main.o: main.c lib/core.h lib/Cronista.h lib/participante.h lib/admin.h
	gcc -c main.c  

core.o: lib/core.c lib/core.h
	gcc -c lib/core.c

Cronista.o: lib/Cronista.c lib/Cronista.h
	gcc -c lib/Cronista.c 

participante.o: lib/participante.c lib/participante.h
	gcc -c lib/participante.c

clean:
	del main.o fecha.o cadena.o main.exe
	cls