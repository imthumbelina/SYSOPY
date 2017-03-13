static:list.c main.c
	gcc -c -Wall list.c -o list.o
	ar rcs liblist.a list.o
	gcc -Wall main.c -static -L. -llist -o main

shared:list.c main.c
	gcc -fPIC -shared list.c -o liblist.so
	gcc main.c -L. -llist -o main

run: shared
	LD_LIBRARY_PATH=. ./main

clean:
	rm *.o *.a *.so
