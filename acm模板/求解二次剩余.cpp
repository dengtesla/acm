#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prime[7600000];
bool isprime[76000000];

ll poww(ll a,ll b,ll p)
{
    ll ans = 1,base = a;
    while(b)
    {
        if(b&1)
        {
            ans*=base;
            ans %= p;
        }
        base*= base;
        base %= p;
        b>>=1;
    }
    return ans;
}
ll b[20],m[20];
ll shank(ll a,ll p) ///get x^2=a(mod p)
{
    if(!isprime[p]) return -1;
    a%=p;
    a+=p;
    a%=p;
    if(poww(a,(p-1)/2,p)!=1) return -1;
    ll q = p-1;
    ll k = 0;
    while(q%2==0)
    {
        k++;
        q/=2;
    }
    ll f;
    for(int i=2;i<p;i++)
    {
        if(poww(i,(p-1)/2,p)!=1)
        {
            f = i;
            break;
        }
    }
    ll g = poww(f,q,p);
    b[1] = poww(a,q,p);
    int i = 1;
    while(b[i]!=1)
    {
        m[i] = 1;
        int wa = 2;
        while(poww(b[i],wa,p)!=1)
        {
            m[i]++;
            wa *= 2;
        }
        i++;
        b[i] = b[i-1]%p*poww(g,poww(2,k-m[i-1],p-1),p)%p;
    }
    int r = i-1;

    ll x =  poww(a,(q+1)/2,p);
    ll times = 0;
    for(int i=1;i<=r;i++)
    {
        times += poww(2,k-1-m[i],p-1);
    }
    x *= poww(g,times,p);
    x %= p;
    return x;
}


int main()
{
    int a,p;
    cin >> a >> p;
    cout << shank(a,p) << endl;
}



