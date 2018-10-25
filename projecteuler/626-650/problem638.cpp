#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9+7;

ll poww(ll a,ll b,ll p)
{
    ll ans = 1;
    ll base = a;
    while(b)
    {
        if(b&1)
        {
            ans *= base;
            ans %= p;
        }
        base *= base;
        base %= p;
        b>>=1;
    }
    return ans;
}


ll qbinomial(ll n,ll m,ll q)
{
    ll res = 1;
    for(ll i = 0;i<=m-1; i++)
    {
        res *= (poww(q,n-i,mod)-1);
        res %= mod;
    }
    for(ll i=m;i>=1;i--)
    {
        res *= poww((poww(q,i,mod)-1),mod-2,mod);
        res %= mod;
    }
    return res;
}

int main()
{
    //cout << qbinomial(4,2,2) << endl;
    //cout << qbinomial(20000,10000,4) << endl;
    ll ans = 705432;
    for(ll k=2;k<=7;k++)
    {
        ans += qbinomial(2*(poww(10,k,mod)+k),poww(10,k,mod)+k,k);
        ans %= mod;
        //cout << k << " is done!" << endl;
    }
    cout << ans << endl;
}
