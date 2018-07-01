#include<bits/stdc++.h>
using namespace std;


int prime[1000000];
bool isprime[1000000];

void get_prime(int listsize)
{
    int primesize=1;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[primesize++]=i;
        for(int j=1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}



int n,cnt;

void solve(int sum,int pre)
{
    if(sum==n)
    {
        cnt++;
        return ;
    }
    for(int i=pre;prime[i]<=n-sum;i++)
    {
        solve(sum+prime[i],i);
    }
}



int main()
{
    get_prime(10000);
    for(n=10;n<=1000;n++)
    {
        cnt = 0;
        solve(0,1);
        if(isprime[n])
        {
            if(cnt-1>5000)
            {
                cout << n << endl;
                break;
            }
        }
        else
        {
            if(cnt>5000)
            {
                cout << n << endl;
                break;
            }
        }
    }



}
