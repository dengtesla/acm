#include<stdio.h>
#include<math.h>
#define N 1e9

int main()
{
    long long a[10000];
    int n,i;
    a[1]=1;
    a[2]=1;
    scanf("%d",&n);
    for(i=3;i<=n;i++)
    {
      //  if(i==1||i==2)
        //    printf("f(%d) = %d\n",i,a[i]);
       // else
        //{
            a[i]=a[i-1]+a[i-2];
            a[i]=a[i]%1000000007;
        //}
    }printf("f(%d) = %lld\n",n,a[n]);
}
