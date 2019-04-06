#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int sec_size = 64000000;
ll poww(ll a,ll b)
{
    ll ans = 1;
    ll base = a;
    while(b)
    {
        if(b&1) ans *= base;
        base *= base;
        b>>=1;
    }
    return ans;
}

ll p[7000000];
bool isp[70000000];
int tot = 0;

void sieve(int n)
{
    memset(isp,1,sizeof isp);
    isp[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(isp[i]) p[++tot] = i;
        for(int j=1;j<=tot&&p[j]*i<=n;j++)
        {
            isp[p[j]*i] = 0;
            if(i%p[j]==0) break;
        }
    }
}

vector < pair<int,ll> > w[7000000];

void init()
{
    for(int i=1;i<=tot;i++)
    {
        ll pend = p[i];
        ll now = 1;
        for(int time = 1;time<=30;time++)
        {
            if(sec_size/now<pend) break;
            now *= pend;
            ll res = now*pend-1;
            res /= pend - 1;
            if(time%2==1)
            {
                res /= pend+1;
                res *= now*pend+1;
            }
            else
            {
                ll res2 = now*pend+1;
                res2 /= pend+1;
                res *= res2;
            }
            w[i].push_back({time,res});
        }
    }
}

long long ans[64000100];
int cnt = 0;
void dfs(ll rua,int k,int times)
{
    if(times!=0) ans[rua] = ans[rua/poww(p[k],times)]*w[k][times-1].second;
    for(int i=k;i<=tot;i++)
    {
        if(rua*p[i]>sec_size) return;
        if(i==k) dfs(rua*p[i],i,times+1);
        else
        {
            dfs(rua*p[i],i,1);
        }
    }
}

int main()
{
    ans[1] = 1;
    sieve(sec_size);
    init();
    dfs(1,1,0);
    cout << "ok" << endl;
    //cout << "ok" << cnt << endl;
    ll res = 0;
    for(int i=1;i<64000000;i++)
    {
        ll w = (int)(sqrt(ans[i])+0.5);
        if(w*w==ans[i])
            res += i;
    }
    cout << res << endl;
}
/*
111111
2 5
3 10
4 21
5 26
6 50
7 50
8 85
9 91
10 130
11 122
12 210
13 170
14 250
15 260
16 341
17 290
18 455
19 362
20 546
*/
