#include<bits/stdc++.h>
using namespace std;
int a[1001];

void init()
{
    for(int i=0;i<=1000;i++)
    {
        a[i] = i*i*2;
    }
}

int prime[1000100];
bool isprime[1000100];

void get_prime(int n)
{
    int tot = 1;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]) prime[tot++] = i;
        for(int j=1;prime[j]*i<=n&&j<=tot;j++)
        {
            isprime[i*prime[j]] = 0;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    get_prime(1000010);
    init();
    for(int i=3;i<=1000000;i+=2)
    {
        bool flag = 0;
        if(!isprime[i])
        {
            for(int j=1;i-a[j]>=0;j++)
            {
                if(isprime[i-a[j]])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==1) ;
            else
            {
                cout << i << endl;
                break;
            }
        }
    }
}
