#include<bits/stdc++.h>
using namespace std;
#define MOD 10000000000

long long poww(int a)
{
    int t = a;
    long long res = 1;
    while(t--)
    {
        res *= a;
        res = res % MOD;
    }
    return res;
}


int main()
{
    long long ans = 0;
    for(int i=1;i<=1000;i++)
    {
        ans += poww(i);
        ans = ans % MOD;
    }
    cout << ans << endl;
}
