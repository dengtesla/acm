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

int pending(int a,int b,int c)
{
    int aa[4];
    int bb[4];
    int cc[4];
    int i = 0;
    int w = 4;
    while(w--)
    {
        aa[i] = a%10;
        bb[i] = b%10;
        cc[i] = c%10;
        a /= 10;
        b /= 10;
        c /= 10;
        i++;
    }
    sort(aa,aa+4);
    sort(bb,bb+4);
    sort(cc,cc+4);
    bool flag = 0;
    w = 4;
    while(w--)
    {
        i--;
        if(aa[i]==bb[i]&&bb[i]==cc[i]) ;
        else flag = 1;
    }
    if(flag==1) return 0;
    else return 1;
}

int main()
{
    get_prime(11000);
    for(int i=169;prime[i]<10000;i++)
    {
        for(int j=i+1;prime[j]<10000;j++)
        {
            if(isprime[2*prime[j]-prime[i]]&&(2*prime[j]-prime[i])<10000)
            {
                if(pending(prime[i],prime[j],2*prime[j]-prime[i])&&prime[i]!=1487)
                    cout << prime[i] << prime[j] << 2*prime[j]-prime[i] << endl;
            }
        }
    }
}

