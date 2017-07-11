#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define N 10000
//Thanks to lth
int main()
{
    double R,r;
    int K,T,k;
    k=1;
    double x,y,xk[N],yk[N],xmax,xmin,xmid,length1,length2,rk[N];
    // y=pow(((0.25-x*x/((R+r)*(R+r)))*(R*R+r*r)),1/2);
    //  rk[0]=R-r;
    //xk[0]=(R+r)/2;
    //yk[0]=0;
    //xmax=(3*r-R)/2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%d",&R,&r,&K);
        rk[0]=R-r;
        xk[0]=(R+r)/2;
        yk[0]=0;
        rk[1]=0;
        for(int i=1; i<=1000; i++)
        {
            xmax=xk[i-1];
            xmin=-(R+r)/2;
            xmid=(xmax+xmin)/2;
            for(int j=1; j<=100; j++)
            {
                xmid=(xmax+xmin)/2;
                x=xmid;
                y=sqrt(((0.25*(R+r)*(R+r)-x*x)*(4*R*r)));
                length1=sqrt((x-(r-R)/2)*(x-(r-R)/2)*(R+r)*(R+r)+y*y)-r*(R+r);
                length2=sqrt((x-xk[i-1])*(x-xk[i-1])*(R+r)*(R+r)+(y-yk[i-1])*(y-yk[i-1]))-rk[i-1]*(R+r);
                // printf("%lf \n",length1);
                if(length1<=length2)
                {
                    xmin=xmid;
                }
                else
                {
                    xmax=xmid;
                }
                xk[i]=x;
                yk[i]=y;
                rk[i]=length1/(R+r);
                x=0;
                y=0;
                length1=0;
                length2=0;
            }
        }
        // for(int i=1;i<=100;i++)
        //  printf("%lf %.4lf\n",rk[i],rk[i]);
        printf("Case #%d:\n",k);
        printf("%.4lf\n",rk[K]);
        k++;
    }
}
