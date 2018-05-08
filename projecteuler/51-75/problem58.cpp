#include<bits/stdc++.h>
using namespace std;
/*
#define MAXIMUM 26
int prime[4000000];
bool isprime[5000000];

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
*/
/*
const int count1=10;
int modular_exp(int a,int m,int n)
{
    if(m==0)
        return 1;
    if(m==1)
        return (a%n);
    long long w=modular_exp(a,m/2,n);
    w=w*w%n;
    if(m&1)
        w=w*a%n;
    return w;
}
bool Miller_Rabin(long long n)
{
    if(n==2)
        return true;
    for(int i=0;i<count1;i++)
    {
        long long a=rand()%(n-2)+2;
        if(modular_exp(a,n,n)!=a)
            return false;
    }
    return true;
}
*/
typedef long long LL;
LL iprime[6] = {2, 3, 5, 233, 331};
LL qmul(LL x, LL y, LL mod) { // 乘法防止溢出， 如果p * p不爆LL的话可以直接乘； O(1)乘法或者转化成二进制加法


    return (x * y - (long long)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
    /*
    LL ret = 0;
    while(y) {
        if(y & 1)
            ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
    */
}
LL qpow(LL a, LL n, LL mod) {
    LL ret = 1;
    while(n) {
        if(n & 1) ret = qmul(ret, a, mod);
        a = qmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}
bool Miller_Rabin(LL p) {
    if(p < 2) return 0;
    if(p != 2 && p % 2 == 0) return 0;
    LL s = p - 1;
    while(! (s & 1)) s >>= 1;
    for(int i = 0; i < 5; ++i) {
        if(p == iprime[i]) return 1;
        LL t = s, m = qpow(iprime[i], s, p);
        while(t != p - 1 && m != 1 && m != p - 1) {
            m = qmul(m, m, p);
            t <<= 1;
        }
        if(m != p - 1 && !(t & 1)) return 0;
    }
    return 1;
}

int main()
{
    //get_prime(5000000);
    long double rate = 1;
    int all = 1;
    int prime_count = 0;
    int roll = 1;
    long long a = 1;
    while(all<=prime_count*10||all==1)
    {
        a+=2*roll;
        all ++;
        if(Miller_Rabin(a)) prime_count++;
        a+=2*roll;
        all++;
        if(Miller_Rabin(a)) prime_count++;
        a+=2*roll;
        all++;
        if(Miller_Rabin(a)) prime_count++;
        a+=2*roll;
        all++;
        //rate = (long double)prime_count/(long double)all;
        roll++;
        //if(prime_count==5243)
          //  break;
        //cout << rate << endl;
    }
    //cout << "prime:" << prime_count << " all:" << all << endl;
    cout << 2*roll-1 << endl;
}
