#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;


int p[20000000+50];
bool isp[20000000+50];
int mu[20000000+50];
ll nn;
ll sqr;

void sieve()
{
    memset(isp,1,sizeof(isp));
    mu[1] = 1;
    int tot = 0;
    for(int i=2;i<=20000000;i++)
    {
        if(isp[i])
        {
            p[++tot] = i;
            mu[i] = -1;
        }
        for(int j=1;j<=tot&&p[j]*i<=20000000;j++)
        {
            isp[i*p[j]] = 0;
            if(i%p[j]==0)
            {
                mu[i*p[j]] = 0;
                break;
            }
            mu[i*p[j]] = mu[i]*-1;
        }
    }

    for(int i=2;i<=20000000;i++)
    {
        mu[i] += mu[i-1];
    }

}

ll S1[500000];
ll S2[500000];

ll getS(ll n)
{
    if(n<=20000000) return mu[n];
    if(n<=sqr&&S1[n]!=0) return S1[n];
    else if(n>sqr&&S2[nn/n]!=0) return S2[nn/n];
    ll res = 1;
    for(ll i=1;i<=n;)
    {
        if(i==n) break;
        res -= (getS(i)%mod)*((n/i-n/(i+1))%mod)%mod;
        res %= mod;
        i = n/(n/(i+1));
    }
    if(n<=sqr) return S1[n] = res%mod;
    else return S2[nn/n] = res%mod;

}

ll get_mu(ll n)
{
    if(n<=20000000) return mu[n];
    if(n<=sqr) return S1[n];
    else return S2[nn/n];
}


ll get_sum(ll n)
{
    ll res = 0;
    for(ll i=1;i<=n;)
    {
        ll step = (i%mod)*(i%mod)%mod;
        ll len = (get_mu(n/i) - get_mu(n/(i+1)))%mod;
        res = res + (len*step%mod);
        res %= mod;
        if(i==n) break;
        i = (n/(n/(i+1)));
    }
    return res;
}

int main()
{
    nn = 100000000000;
    sqr = (ll)sqrt(nn);
    //cout << sqr << endl;
    sieve();
    getS(nn);
    cout << "******" << endl;
    ll txt = 2;
    ll ans = 0;
    while(txt<=nn)
    {
        ans += get_sum(nn/txt);
        ans %= mod;
        txt*=2;
    }
    //cout << (int)log2(nn) << endl;
    ans -= (ll)log2(nn);
    ans %= mod;
    ans += mod;
    ans %= mod;
    ans *= (mod+1)/2;
    ans %= mod;
    cout << ans << endl;
}
