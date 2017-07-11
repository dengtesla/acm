#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
#define N 10000

int main()
{
    int a,b;
    int x1,y1;
    int x2,y2;
    int flag=0;
    cin >> a >> b;
    for(int i=1;i<a;i++)
    {
        for(int j=1;j*j+i*i<=a*a;j++)
        {
            if(j*j+i*i==a*a)
            {
                x1 = i;
                y1 = j;
                if((x1*b)%a==0&&(y1*b)%a==0)
                {
                    y2 = (x1*b)/a;
                    x2 = -(y1*b)/a;
                    if(y1!=y2)
                    {
                        printf("YES\n");
                        printf("0 0\n");
                        printf("%d %d\n",x1,y1);
                        printf("%d %d\n",x2,y2);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 1)
            break;
    }
    if(flag!=1)
    {
        printf("NO");
    }
    return 0;
}
