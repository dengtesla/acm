#include<bits/stdc++.h>
using namespace std;
#define MAXIMUM 13


int prime[1000000];
bool isprime[1000000];
int aa[4];


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


struct p
{
    int value;
    int time;
}p[MAXIMUM];

int prime_factorization(int a)
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
    return psize;
}

int main()
{
    get_prime(1000000);
    aa[1] = 0;
    aa[2] = 1;
    aa[3] = 1;
    aa[4] = 1;
    for(int i=1;i<=1000000;i++)
    {
        if(i%4==1)
            aa[1] = prime_factorization(i);
        else if(i%4==2)
            aa[2] = prime_factorization(i);
        else if(i%4==3)
            aa[3] = prime_factorization(i);
        else
            aa[4] = prime_factorization(i);
        if(aa[1]==4&&aa[2]==4&&aa[3]==4&&aa[4]==4)
        {
            cout << i-3 << endl;
            break;
        }
    }
}

