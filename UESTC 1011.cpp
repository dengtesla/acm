#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,sum,s,b,c,sume;
    int tri[100][100];
    memset(tri,0,sizeof(tri));
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                scanf("%d",&tri[i][j]);
        }
        c=1;sum=0;
        while(c<=n)
        {
            s=n;b=c;
            sum=tri[s][b];
            while(s>1)
            {
                if(s<=b)
                {
                    b=s;
                    tri[s-1][b]=0;
                }
                if(tri[s-1][b]>tri[s-1][b-1])
                {
                    sum=sum+tri[s-1][b];
                }
                else
                {
                    sum=sum+tri[s-1][b-1];
                    b=b-1;
                    if(b==0)
                        b=1;
                }
                s--;
            }
            if(sume<sum)
                sume=sum;
            sum=0;
            c++;
        }
        printf("%d",sume);
    }
}

