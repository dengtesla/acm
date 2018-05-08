#include<bits/stdc++.h>
using namespace std;

int prime[1000000],primesize=0;
bool isprime[1000000];

void getlist(int listsize)
{

    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[++primesize] = i;
        for(int j=1;j<=primesize&i*prime[j]<=listsize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

struct p
{
    int value;
    int time;
}p[1000];

void prime_factorization(int a)
{
    memset(p,0,sizeof(p));
    int psize=0;
    int n = a;
    for(int t = 1;t<=n;t++)
    {
        if(a%prime[t]==0) p[++psize].value = prime[t];
        while(a%prime[t]==0)
        {
            p[psize].time += 1;
            a = a / prime[t];
        }
        if(isprime[a])
        {
            p[++psize].value = a;
            p[psize].time += 1;
            break;
        }
        if(a==1) break;
    }
}

int main()
{
    int abundant[100000];
    memset(abundant,0,sizeof(abundant));
    getlist(100000);
    int psize = 0;
    int sum1 = 1;
    int sum2 = 1;
    int ans=0;
    for(int i = 2;i<=28123;i++)
    {
        sum2 = 1;
        prime_factorization(i);
        int j = 1;
        while(p[j].value!=0)
        {
            sum1 = 1;
            while(p[j].time!=0)
            {
            sum1 *= p[j].value;
            p[j].time--;
            }
            sum2 *= (sum1*p[j].value-1)/(p[j].value-1);
            j++;
        }
        //cout << sum2 << endl;
        if((sum2-i)>i) abundant[++psize] = i;
    }
    //for(int i=6000;i<=6999;i++)
    //cout << abundant[i] << " ";

    bool isdouble[60000];
    memset(isdouble,1,sizeof(isdouble));
    for(int i=1;abundant[i]!=0;i++)
    {
        for(int j=i;abundant[j]!=0;j++)
        {
            if(isdouble[abundant[i]+abundant[j]]==1) isdouble[abundant[i]+abundant[j]]=0;
        }
    }
    for(int i=1;i<=20161;i++) //其实20161是上确界，也就是说对于一切比20161大的数一定能表示成两个盈数的和，题目里给的28123不是充要的。
    {
        if(isdouble[i]==1) // cout << i << " ";
            ans+=i;
    }
    cout << ans << endl;

}



