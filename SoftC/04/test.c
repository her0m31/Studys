#include <stdio.h>
#include <stdlib.h>

int main()
{
        double i,imax,n;
        double x,y,pi;

        n=0.0;
        imax=10000000.0;        //      乱数の発生回数

        for(i=0;i<=imax;i++) {
/*0以上1未満の乱数を生成*/
                x=rand()/(RAND_MAX+1.0);
                y=rand()/(RAND_MAX+1.0);        

/*0<=x,y<=1の範囲にある中心原点半径1の
扇形の中に乱数による点が入ったらカウントする*/
                if((x*x+y*y)<1.0) {                     
                        n+=1.0;                                 
                }
        }

        pi=n/imax*4.0;          //半径1の円の面積すなわち円周率

        printf("%f\n",pi);

        return 0;
}
