#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(n%4==3)
            {
                if(i%2!=0)
                {
                    printf("#");
                }
                else if(i%4==2)
                {
                    if(j!=m)
                        printf(".");
                    else
                        printf("#");
                }
                else if(i%4==0)
                {
                    if(j!=1)
                        printf(".");
                    else
                        printf("#");
                }
                if(j==m)
                    printf("\n");
            }
            else
            {
                if(i%2!=0)
                {
                    printf("#");
                }
                else if(i%4==0)
                {
                    if(j!=1)
                        printf(".");
                    else
                        printf("#");
                }
                else if(i%4==2)
                {
                    if(j!=m)
                        printf(".");
                    else
                        printf("#");
                }
                if(j==m)
                    printf("\n");
            }
        }
    }
}
