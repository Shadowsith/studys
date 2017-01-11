rechner: main.o functions.o
	  gcc main.o functions.o -lm -o rechner

main.o:	main.c
	  gcc -c main.c
	  
functions.o: functions.c
		gcc -c -lm functions.c

	  
clean: main.o rechner
	rm -rf main.o functions.o rechner
