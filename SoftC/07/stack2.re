$ make
cc    -c -o main1.o main1.c
cc    -c -o push_pop2.o push_pop2.c
cc -o stack2 main1.o push_pop2.o
$ ./stack2
-2.11 0.68 -1.48 0.37 3.21 1.54 0.53 -0.93 1.60 2.84 0.52 
0.52 2.84 1.60 -0.93 0.53 1.54 3.21 0.37 -1.48 0.68 -2.11 