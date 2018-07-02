#include<bits/stdc++.h>
using namespace std;

const long long MAX = 10100000;
bool isprime[MAX+10];
long long prime[MAX+10];
long long euler[MAX+10];

void get_euler(long long n)
{
    euler[1] = 1;
    long long tot = 0;
    memset(isprime,1,sizeof(isprime));
    for(long long i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            prime[++tot] = i;
            euler[i] = i-1;
        }
        for(long long j=1;prime[j]*i<=n;j++)
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



int main()
{
    get_euler(10000000);
    long double ww = 1.0*15499/94744;
    long long ans = 10000000000000000;
    long long sum = 1;
    long double r = 1;
    for(int i=1;sum<=10000000000000000;i++)
    {
        sum *= prime[i];
        r*=(1.0-1.0/(1.0*prime[i]));
        //cout << r << endl;
        if(r<ww)
        {
            int k = 1;
            while(1.0*(1.0*k*sum)/(1.0*k*sum-1.0)*r>=ww)
            {
                k++;
            }
            ans = min(ans,k*sum);
        }
    }
    cout << ans << endl;
}



