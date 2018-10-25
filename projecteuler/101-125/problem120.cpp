#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long ans = 0;
    for(int a=3;a<=1000;a++)
    {
        int res = 2;
        for(int n=1;n<=a*2;n+=2)
        {
            res = max(res,(2*n*a)%(a*a));
        }
        //if(a==3) cout << res << endl;
        ans += res;
    }
    cout << ans << endl;
}
