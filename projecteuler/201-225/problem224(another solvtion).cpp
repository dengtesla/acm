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
const ll mmax = 75000000;

vector <int> f[30000000+100];

int fac_num[200];
int fac_tim[200];

int ans = 0;


void dfs(ll x,ll res,ll now,ll fin)
{
    if(now>fin)
    {
        ll w = (x*x + 1)/res;
        if(w<=res) return;
        ll z = (w+res)/2;
        ll y = (w-res)/2;
        if(__gcd(x,__gcd(y,z))!=1) return;
        if(x<=y&&y<z&&(x+y+z)<=75000000)
        {
            ans++;
            //if(z<=200)
            //    cout << x << " " << y << " " << z << endl;
        }
        return;
    }
    else
    {
        for(int i=0;i<=fac_tim[now];i++)
        {
            dfs(x,res*poww(fac_num[now],i,1000000000),now+1,fin);
        }
    }
}



int main()
{
    get_prime(75500000);
    //cout << "STEP 1 IS DONE!" << endl;
    for(int i=1;prime[i]<=mmax;i++)
    {
        ll w1 = shank(-1,prime[i]); ///找到x^2=-1(mod prime[i])的一个解,-1表示没有
        if(w1==-1) continue; /// 没有就排除，x^2+1一定不可能有这个质因子
        ll w2 = ((-w1 + prime[i])%prime[i] + prime[i])%prime[i];///二次剩余的另一个解
        for(ll j=0;w1+j*prime[i]<=30000000;j++)
        {
            ll x = w1 + j*prime[i];
            ll pend = 1ll*x*x + 1;
            while(pend%prime[i]==0) ///把x^2+1的所有prime[i]全都推进vector里
            {
                pend /= prime[i];
                f[x].push_back(prime[i]);
            }
        }

        for(ll j=0;w2+j*prime[i]<=30000000;j++)
        {
            ll x = w2 + j*prime[i];
            ll pend = 1ll*x*x + 1;
            while(pend%prime[i]==0)
            {
                pend /= prime[i];
                f[x].push_back(prime[i]);
            }
        }
        //cout << prime[i] << endl;
    }
/*
    for(int i=1;i<=30;i++)
    {
        cout << i*i+1 << " : ";
        for(auto iter = f[i].cbegin();iter != f[i].cend();iter++)
        {
            cout << (*iter) << " ";
        }
        cout << endl;
    }
*/
    //cout << "STEP 2 IS DONE!" << endl;
    /*
    int i;
    while(cin >> i)
    {
        cout << i*i+1 << " : ";
        for(auto iter = f[i].cbegin();iter != f[i].cend();iter++)
        {
            cout << (*iter) << " ";
        }
        cout << endl;
    }
*/
    for(int i=1;i<=30000000;i++)
    {
        if((1ll*i*i+1)%2==0) continue;
        if(f[i].empty()) continue;
        ll res = 1;
        for(auto iter = f[i].cbegin();iter != f[i].cend();iter++)
        {
            res = 1ll*(*iter)*res;
        }
        if(res!=1ll*i*i+1) continue; ///如果i的vector里所有的素因子乘起来不等于i^2+1,说明这个i一定不可能是一个合理的x，剪枝。

        int it = 0;
        for(auto iter = f[i].cbegin();iter != f[i].cend();iter++)
        {
            if(iter==f[i].cbegin())
            {
                fac_num[it] = (*iter);
                fac_tim[it] = 1;
            }
            else
            {
                if((*iter)==fac_num[it]) fac_tim[it]++;
                else
                {
                    it++;
                    fac_num[it] = (*iter);
                    fac_tim[it] = 1;
                }
            }
        }

        dfs(i,1,0,it);
    }
    cout << ans << endl;

}
