#include <stdio.h>
#include <stdlib.h>

int main()
{
        double i,imax,n;
        double x,y,pi;

        n=0.0;
        imax=10000000.0;        //      �����ȯ�����

        for(i=0;i<=imax;i++) {
/*0�ʾ�1̤�������������*/
                x=rand()/(RAND_MAX+1.0);
                y=rand()/(RAND_MAX+1.0);        

/*0<=x,y<=1���ϰϤˤ����濴����Ⱦ��1��
������������ˤ���������ä��饫����Ȥ���*/
                if((x*x+y*y)<1.0) {                     
                        n+=1.0;                                 
                }
        }

        pi=n/imax*4.0;          //Ⱦ��1�αߤ����Ѥ��ʤ���߼�Ψ

        printf("%f\n",pi);

        return 0;
}
