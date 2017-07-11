#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c,d,sum,i,j;
    d=1;
while(d<100000){
    scanf("%d",&a);
    scanf("%d",&b);
    sum=0;
    if(a!=0&&b!=0){
    for(i=0;i<=99;i++)
    {
        c=i+a*100;
        if(c%b==0)
        {
            sum=sum+1;
            if(sum==1){
                if(i<10)
                    printf("0%d",i);
                else
                    printf("%d",i);
            }
            else
            {
                if(i<10)
                    printf(" 0%d",i);
                else
                    printf(" %d",i);
            }
        }
        if(i==99)
            printf("\n");
    }
    }
    else
        return 0;
}
}
