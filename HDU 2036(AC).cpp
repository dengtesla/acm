#include<cstdio>
#include<cmath>
int x[1000003],y[1000003];
double A,tx,ty,tmp;
int main(void)
{
    int cases,n,i,p;
    p=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        A=0.0;
        x[0]=y[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            A+=(x[i-1]*y[i]-x[i]*y[i-1]);
        }
        A+=x[n]*y[1]-x[1]*y[n];
        A=A/2.0;
        tx=ty=0.0;
        for(i=1;i<n;i++)
        {
            tmp=x[i]*y[i+1]-x[i+1]*y[i];
            tx+=(x[i]+x[i+1])*tmp;
            ty+=(y[i]+y[i+1])*tmp;
        }
        tmp = x[n]*y[1] - x[1]*y[n];
        tx += (x[n]+x[1])*tmp;
        ty += (y[n]+y[1])*tmp;
       // printf ("%.2lf %.2lf\n", tx/(6.0*A), ty/(6.0*A));
        printf("%.1lf\n",A);
    }
    return 0;
}
