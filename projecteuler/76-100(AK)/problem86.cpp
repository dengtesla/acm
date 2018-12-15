#include<bits/stdc++.h>
using namespace std;
int times;
#define ll long long


ll f(ll a,ll b,ll c,ll n) ///用于求解$Sigma_{i=0}^{n} floor((a*i+b)/c)$
{
    ll m = (a*n+b)/c;
    if(n==0||m==0) return (b/c);
    if(n==1) return ((b/c)+((a+b)/c));
    if(a<c&&b<c) return m*n - f(c,c-b-1,a,m-1);
    else return (a/c)*n*(n+1)/2 + (b/c)*(n+1) + f(a%c,b%c,c,n);
}



void dfs(int a,int b,int c,int sz)
{

    int aa = min(a,b);
    int bb = max(a,b);
    if(bb<=sz)
    {
        int k = sz/bb;
        times += f(aa,0,2,k);
    }

    if(aa<=sz&&2*aa>=bb)
    {
        int k = sz/aa;
        times += f(2*aa-bb,0,2,k)+k;
    }

    if(aa>sz) return;

    dfs(a-2*b+2*c,2*a-b+2*c,2*a-2*b+3*c,sz);
    dfs(a+2*b+2*c,2*a+b+2*c,2*a+2*b+3*c,sz);
    dfs(2*b+2*c-a,b+2*c-2*a,2*b+3*c-2*a,sz);
}

int get_num(int k)
{
    times = 0;
    dfs(3,4,5,k);
    return times;
}

int main()
{
    int l = 1,r = 5000,mid;
    while(l<r)
    {
        mid = (l+r)/2;
        if(get_num(mid)>1000000)
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    cout << mid << endl;

}
