#include<bits/stdc++.h>
using namespace std;
#define MAXIMUM 13


//将小于listsize的质数全都按大小顺序存在prime[]数组里（prime[1]=2）
//同时可以调用isprime[]数组O(1)查询某个数是不是质数（例如isprime(8)=0，说明8不是质数）
//复杂度O(n)
int prime[1000000];
bool isprime[1000000];

void get_prime(int listsize)
{
    int primesize=0;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[++primesize]=i;
        for(int j=1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

//将数a质因数分解，将其质因子从小到大存在结构体p[].value中，次数存在p[].time中
struct p
{
    int value;
    int time;
}p[MAXIMUM];

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

int power(int a,int b)
{
    int res=1;
    for(int i=1;i<=b;i++)
    {
        res *= a;
    }
    return res;
}

int d(int i)
{
    prime_factorization(i);
    int j = 1,dd=1;
    while(p[j].value!=0)
    {
        dd *= (power(p[j].value,p[j].time+1)-1)/(p[j].value-1);
        j++;
    }
    dd -= i;
    //cout << ans << endl;
    return dd;
}

int main()
{
    get_prime(10100);
    bool istrue[101000];
    int ans = 0;
    //cout << d(220) << endl;
    memset(istrue,true,sizeof(istrue));
    for(int i = 1;i<=10000;i++)
    {
        if(istrue[i]&&d(i)<=10000)
        {
            if(d(i)!=i&&i==d(d(i))) ans += d(i)+i;
            //cout << ans << endl;
            istrue[i]=0;
            istrue[d(i)]=0;
        }
    }
    //cout << d(0) << endl;
    cout << ans-1 << endl; //1不是亲和数，但是d(1)=0,d(0)=1
}
