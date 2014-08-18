$ make
cc    -c -o main2.o main2.c
cc    -c -o push_pop.o push_pop.c
cc -o poli main2.o push_pop.o
$ ./poli
1.7 2.8 + 2.5 4.7 - * -0.1 +
-10.00 