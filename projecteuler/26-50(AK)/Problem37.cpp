#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int prime[MAX+10];
bool isprime[MAX+10];
int tot = 1;

void get_prime(int n)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]) prime[tot++] = i;
        for(int j=1;prime[j]*i<=n&&j<=tot;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

int poww(int a,int n)
{
    int res = 1;
    while(n)
    {
        res *= a;
        n--;
    }
    return res;
}

int number(int n)
{
    int res = 0;
    while(n)
    {
        n/=10;
        res++;
    }
    return res;
}

int prev_number(int n)
{
    int a = n/poww(10,number(n)-1);
    n -= a*poww(10,number(n)-1);
    return n;
}

int main()
{
        get_prime(1000000);
        int cnt = 0;
        for(int i=5;prime[i]!=0;i++)
        {
            bool flag = 0;
            int a = prime[i];
            while(a)
            {
                a = prev_number(a);
                if(isprime[a]) ;
                else
                {
                    flag = 1;
                    break;
                }
            }
            a = prime[i];
            while(a)
            {
                a /= 10;
                if(isprime[a]) ;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) cnt += prime[i];
        }
        cout << cnt << endl;
}
