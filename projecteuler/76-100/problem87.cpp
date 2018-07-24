#include<bits/stdc++.h>
using namespace std;


long long prime[1000000];
bool isprime[1000000];

void get_prime(long long listsize)
{
    long long primesize=1;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(long long i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[primesize++]=i;
        for(long long j=1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}


long long tt[10000000];

int main()
{
    get_prime(100000);
    int a;
    long long n = 50000000;
    long long cnt = 0;
    for(long long i=1;prime[i]<=84;i++)
        for(long long j=1;prime[j]<=368;j++)
            for(long long k=1;prime[k]<=7081;k++)
            {
                long long res = prime[i]*prime[i]*prime[i]*prime[i] + prime[j]*prime[j]*prime[j] + prime[k]*prime[k];
                if(res<n)
                {
                    tt[cnt] = res;
                    cnt++;
                }
                else
                    break;
            }
    sort(tt,tt+cnt);
    cout << unique(tt,tt+cnt) - tt << endl;
}
