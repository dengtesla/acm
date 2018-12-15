#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll poww[13];
ll val[13];



ll u(ll a)
{
    ll sta = 1;
    ll now = 1;
    ll res = 0;
    for(int i=0;i<=10;i++)
    {
        res += sta*now;
        sta*=-1;
        now*=a;
    }
    return res;
}

ll gogogo(int times)
{
    if(times==1) return u(1);
    ll fin = 0;
    for(int i=1;i<=times;i++)
    {
        ll res = poww[times];
        res /= times+1-i;
        res *= val[i];
        for(int j=1;j<=times;j++)
        {
            if(j!=i) res /= (i-j);
        }
        fin += res;
    }
    return fin;
}


int main()
{
    poww[0] = 1;
    for(int i=1;i<=13;i++)
    {
        poww[i]=poww[i-1]*i;
        val[i] = u(i);
    }
    ll fin = 0;
    for(int i=1;i<=11;i++)
    {
        ll res = gogogo(i);
        //cout << res << " " << u(i+1) << endl;
        if(res!=u(i+1)) fin += res;
    }
    cout << fin << endl;
}
