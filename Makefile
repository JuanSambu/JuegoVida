# Ejecutable:
juego_vida: main.o frontend.o backend.o general.h
	gcc main.o frontend.o backend.o -o juego_vida -Wall
	
main.o: main.c general.h frontend.h backend.h
	gcc main.c -c -Wall
	
frontend.o: frontend.c frontend.h backend.h general.h
	gcc frontend.c -c -Wall

backend.o: backend.c backend.h general.h
	gcc backend.c -c -Wall
	
clean: 
	rm *.o
