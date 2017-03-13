static: main.c list.c
        gcc -c list.c -o list.o
        ar rcs liblist.a list.o
        gcc main.c -static -L. -llist -o main
        ./main
