all: main


server.o: server.c server.h
	gcc -Wall -c server.c


main:  server.o  main.c
	gcc -Wall -o main -Wall server.o main.c -lm -lpthread

clear:
	rm -rf *.o
	rm main
