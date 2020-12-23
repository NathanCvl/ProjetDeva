bataille: exemple.o main.o
    gcc -o bataille exemple.o main.o
exemple.o: exemple.c
    gcc -o exemple.o -c exemple.c -Wall -O
main.o: main.c exemple.h
    gcc -o main.o -c main.c -Wall -O