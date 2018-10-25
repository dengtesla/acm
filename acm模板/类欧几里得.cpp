#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll g(ll,ll,ll,ll);
ll h(ll,ll,ll,ll);


ll f(ll a,ll b,ll c,ll n) ///用于求解$Sigma_{i=0}^{n} floor((a*i+b)/c)$
{
    ll m = (a*n+b)/c;
    if(n==0||m==0) return (b/c);
    if(n==1) return ((b/c)+((a+b)/c));
    if(a<c&&b<c) return m*n - f(c,c-b-1,a,m-1);
    else return (a/c)*n*(n+1)/2 + (b/c)*(n+1) + f(a%c,b%c,c,n);
}

ll g(ll a,ll b,ll c,ll n) ///用于求解$Sigma_{i=0}^{n} i*floor((a*i+b)/c)$
{
    ll m = (a*n+b)/c;
    if(n==0||m==0) return 0;
    if(a<c&&b<c) return ((n+1)*n*m - f(c,c-b-1,a,m-1) - h(c,c-b-1,a,m-1))/2;
    else return g(a%c,b%c,c,n) + (a/c)*n*(n+1)*(2*n+1)/6 + (b/c)*n*(n+1)/2;
}


ll h(ll a,ll b,ll c,ll n) ///用于求解$Sigma_{i=0}^{n} (floor((a*i+b)/c))^2$
{
    ll m = (a*n+b)/c;
    if(n==0||m==0) return (b/c)*(b/c);
    if(a<c&&b<c) return n*m*(m+1) - g(c,c-b-1,a,m-1)*2 - f(c,c-b-1,a,m-1)*2 - f(a,b,c,n);
    else return h(a%c,b%c,c,n) + (a/c)*(a/c)*n*(n+1)*(2*n+1)/6 + (a/c)*(b/c)*n*(n+1) + (b/c)*(b/c)*(n+1) + (a/c)*g(a%c,b%c,c,n)*2 + (b/c)*f(a%c,b%c,c,n)*2;
}


ll f_sqr(ll a,ll b,ll c,ll n,ll r)  ///用于求解$Sigma_{i=1}^{n} floor(i*(a*sqrt(r)+b)/c)$
{
    double w = sqrt(r);
    if(n==0) return 0;
    if(n==1) return (a*w+b)/c;
    ll gg = __gcd(a,__gcd(b,c));
    a/=gg,b/=gg,c/=gg;
    ll res = (ll)(w*a + 1.0*b)/(1.0*c);
    if(res==0)
    {
        ll gcd = __gcd(a*c,__gcd(b*c,a*a*r-b*b));
        ll nn = (w*a + 1.0*b)/(1.0*c)*n;
        return nn*n - f_sqr(a*c/gcd,b*c*(-1)/gcd,(a*a*r-b*b)/gcd,nn,r);
    }
    else return n*(n+1)/2*res + f_sqr(a,b-res*c,c,n,r);
}


int main()
{
    srand(123);
    ll a,b,c,d,n;
    cin >> d;
    //d = 500;
    while(d--)
    {
        a = rand()%10000;
        b = rand()%10000;
        c = rand()%10000;
        n = rand()%10000;
        cout << h(a,b,c,n) << endl;
        ll ans = 0;
        for(int i=0;i<=n;i++)
        {
            ll m = (a*i+b)/c;
            ans += m*m;
        }
        cout << ans << endl;
        if(ans!=h(a,b,c,n)) cout << "NO" << endl;
    }
    cout << "all right" << endl;
}
