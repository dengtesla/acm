#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const int maxn = 2000;

ll isp[3000000+10];
ll p[3000000+10];
int b[maxn],c[maxn][maxn],Inv[maxn];

ll poww(ll a,int b)
{
    ll ans = 1,base = a%mod;
    while(b)
    {
        if(b&1)
        {
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        b>>=1;
    }
    return ans;
}

ll sigma_f(ll n,int k) ///µÃµ½¡Æi^k, i:1~n
{
    if(k==0) return n;
    n++;
    n%=mod;
    ll tmp = n;
    ll ans=0;
    for (int i=1;i<=k+1;i++)
    {
        ans += 1LL*c[k+1][i]*b[k+1-i]%mod*n%mod;
        ans %= mod;
        n *= tmp%mod;
        n %= mod;
    }
    ans *= Inv[k+1];
    ans %= mod;
    ans += mod;
    ans %= mod;
    return ans;
}



void init()
{
    memset(isp,1,sizeof isp);
    isp[1] = 0;
    int tot = 0;
    for(int i=2;i<=3000000;i++)
    {
        if(isp[i]) p[++tot] = i;
        for(int j=1;j<=tot&&p[j]*i<=3000000;j++)
        {
            isp[p[j]*i] = 0;
            if(i%p[j]==0) break;
        }
    }

    c[0][0]=1;
    for (int i=1;i<maxn;i++)
    {
        for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j]) % mod;
        c[i][0]=1;
    }
    Inv[1]=1;
    for (int i=2;i<maxn;i++) Inv[i]=1LL*Inv[mod % i] * (mod-mod/i) % mod;
    b[0]=1;
    for (int i=1;i<maxn;i++)
    {
        b[i]=0;
        for (int k=0;k<i;k++) b[i]=(b[i]+1LL*c[i+1][k]*b[k] % mod) % mod;
        b[i]=(1LL*b[i]*(-Inv[i+1]) % mod+mod)%mod;
    }

}

int cnt = 0;
const ll fin = 1e12;

struct node
{
    ll val;
    vector <int> fac;
}nod[3000000];

void dfs(ll now,ll now_p,int cc,bool flag)
{
    if(flag==0)
    {
        if(p[now_p]*p[now_p]<=fin/now)
        {
            cnt++;
            int ccc = cnt;
            nod[ccc].val = now*p[now_p]*p[now_p];
            nod[ccc].fac = nod[cc].fac;
            nod[ccc].fac.push_back(now_p);
            dfs(nod[ccc].val,now_p,ccc,1);
            for(int i=1;now*p[now_p+i]*p[now_p+i]<=fin;i++) dfs(nod[ccc].val,now_p+i,ccc,0);
        }
        else return;
    }
    if(flag==1)
    {
        if(p[now_p]<=fin/now)
        {
            cnt++;
            int ccc = cnt;
            nod[ccc].val = now*p[now_p];
            nod[ccc].fac = nod[cc].fac;
            dfs(nod[ccc].val,now_p,ccc,1);
            for(int i=1;p[now_p+i]*p[now_p+i]<=fin;i++) dfs(nod[ccc].val,now_p+i,ccc,0);
        }
        else return;
    }
}


ll g(ll a,ll k)
{
    ll ans = 1;
    for(auto it = nod[a].fac.begin();it!=nod[a].fac.end();it++)
    {
        ll res = poww(p[*it],k)*(1ll-poww(p[*it],k))%mod;
        ans *= res;
        ans %= mod;
    }
    return ans;
}



int main()
{
    init();
    nod[0].val = 1;
    for(int i=1;p[i]*p[i]<=fin;i++)
    {
        dfs(1,i,0,0);
    }/*
    cout << cnt << endl;
    int a;
    while(cin >> a)
    {
        cout << nod[a].val << endl;
        cout << "factor: ";
        for(auto i=nod[a].fac.begin();i!=nod[a].fac.end();i++)
        {
            cout << p[*i] << " ";
        }
        cout << endl;
    }*/
    ll res = 0;
    for(int k=1;k<=50;k++){
    for(int i=1;i<=cnt;i++)
    {
        res += (sigma_f(fin/nod[i].val,k)*g(i,k)%mod);
        res %= mod;
    }
    res += sigma_f(fin,k);
    res %= mod;}
    cout << (res+mod)%mod << endl;
}


