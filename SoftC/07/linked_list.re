$ make
cc    -c -o main3.o main3.c
cc    -c -o linked_list.o linked_list.c
cc -o linked_list main3.o  linked_list.o
$ ./linked_list < p3.dat 
0 1 2 3 4 5 6 7 8 9 
0 2 4 6 8 