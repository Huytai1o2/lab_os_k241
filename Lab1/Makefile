myapp: hello.o in.o
	gcc -o myapp in.o hello.o

hello.o: hello.c
	gcc -c -o hello.o  hello.c

in.o: in.c
	gcc -c -o in.o in.c

clean:
	rm -f *.o
	rm myapp

all:
	myapp
