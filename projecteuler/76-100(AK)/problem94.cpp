#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll isq(ll a)
{
    ll w = round(sqrt(a));
    if(w*w==a) return 1;
    return 0;
}


int main()
{
    ll res = 0;
    for(ll k=1;k<=(1000000000-2)/6;k++)
    {
        if(isq((k+1)*(3*k+1))) res += k*6+2;
    }
    cout << "half!" << endl;
    for(ll k=1;k<=(1000000000-4)/6;k++)
    {
        if(isq((k)*(3*k+2))) res += k*6+4;
    }
    cout << res << endl;
}
