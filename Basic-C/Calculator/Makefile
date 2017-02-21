calculator: main.o functions.o matrix.o
		gcc functions.o -lm  matrix.o main.o -std=c99 -o calculator
main.o: main.c
		gcc -c main.c
	
functions.o: functions.c
		gcc -c functions.c

matrix.o: matrix.c
		gcc -c matrix.c
		
clean: 
	rm -rf calculator functions.o matrix.o main.o
