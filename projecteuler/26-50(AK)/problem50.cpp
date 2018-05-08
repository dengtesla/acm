#include<bits/stdc++.h>
using namespace std;
#define MAXIMUM 13

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

int main()
{
    get_prime(1000000);
    int ans = 1;
    int res = 0;
    for(int i=1;ans*prime[i]<=1000000;i++)
    {
        int tot = prime[i];
        int j = 1;
        while(tot<=1000000&&prime[i+j]!=0)
        {
            tot += prime[i+j];
            if(isprime[tot]&&tot<=1000000)
            {
                if(j+1>=ans) res = tot;
                ans = max(ans,j+1);
            }

            j++;
        }
    }
    cout << res << endl;
}
