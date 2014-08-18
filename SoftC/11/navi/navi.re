$ make
cc    -c -o main5.o main5.c
cc    -c -o read.o read.c
cc    -c -o navi.o navi.c
cc -g -o navi main5.o read.o navi.o
$ ./navi
Please give a start point and a destination as argument.
$ ./navi Morioka
Please give a start point and a destination as argument.
$ ./navi Tokyo Morioka
Start point is not registered.
$ ./navi Morioka Tokyo
Destination point is not registered.
$ ./navi Morioka Ryusendou
The shortes path from Morioka to Ryusendou
           Morioka ->          Iwaizumi by              JR Bus for  85 [min.]
          Iwaizumi ->         Ryusendou by              JR Bus for   7 [min.]
Total time required ... 92[min.]
$ ./navi Morioka Chusonji
The shortest path from Morioka to Chusonji
           Morioka ->        Ichinoseki by  Shinkansen Yamabiko for  25 [min.]
        Ichinoseki ->         Hiraizumi by  Tohoku-Honsen Line for   8 [min.]
         Hiraizumi ->          Chusonji by  Iwateken-Kotsu Bus for   4 [min.]
Total time required ... 37[min.]