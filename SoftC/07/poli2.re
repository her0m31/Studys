$ make
cc    -c -o main5.o main5.c
cc    -c -o push_pop2.o push_pop2.c
cc -o poli2 main5.o push_pop2.o
$ ./poli2 < p4.dat 
1.7 2.8 + 2.5 4.7 - * -0.1 + 3 ^
-1000.000000 
$ ./poli2 < p5.dat 
7 2 + 4 * 9 3 / - 3 %
0.000000 
