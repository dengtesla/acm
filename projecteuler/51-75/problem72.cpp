#include<bits/stdc++.h>
using namespace std;
const int MAX = 1010000;


int mu[MAX+10];
bool isprime[MAX+10];
int prime[MAX+10];

void get_mobius(int n)
{
    mu[1] = 1;
    int tot = 0;
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for(int j=1;prime[j]*i<=n;j++)
        {
            isprime[prime[j]*i] = 0;
            if(i%prime[j]==0)
            {
                mu[prime[j]*i] = 0;
                break;
            }
            mu[prime[j]*i]=-mu[i];
        }
    }
}

int euler[MAX+10];

void get_euler(int n)
{
    euler[1] = 1;
    int tot = 0;
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            prime[++tot] = i;
            euler[i] = i-1;
        }
        for(int j=1;prime[j]*i<=n;j++)
        {
            isprime[prime[j]*i] = 0;
            if(i%prime[j]==0)
            {
                euler[prime[j]*i] = prime[j]*euler[i];
                break;
            }
            euler[prime[j]*i] = euler[i]*(prime[j]-1);
        }
    }
}

//debug
int main()
{
    get_mobius(1000010);
    get_euler(1000010);
    int n=1000000;
    //cin >> n;
    long long res = 0;
    for(int i=1;i<=n;i++)
    {
        res += euler[i];
    }
    cout << res-1 << endl;
}



