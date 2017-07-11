#include<stdio.h>
#include<math.h>
//lth

int main()
{
    int flag=0;
    int num,i;
    scanf("%d",&num);
    for(i=1;i<sqrt(num);i++)
    {
        if(flag)break;
        int res = 2*num-i*i-i;
        int a=0;
        int b=sqrt(res);
        while(a<=b)
        {
            if(flag)break;
            int mid = (a+b)/2;
            if(mid*(mid+1)/2>res)
                b=mid-1;
            else if(mid*(mid+1)==res)
                flag=1;
            else
                a=mid+1;

        }
    }
    if(flag==1)printf("YES");
    else printf("NO");
}
