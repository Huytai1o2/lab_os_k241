all: main

main: main.o rcv.o snd.o
	gcc -o main main.o rcv.o snd.o

main.o: main.c
	gcc -c main.c

rcv.o: rcv.c
	gcc -c rcv.c

snd.o: snd.c
	gcc -c snd.c

clean:
	rm -f *.o main
