#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 1;
    int t = 2;
    int cnt = 0;
    int n=1001;
    int num=1;
    while(t<=n-1)
    {
        num+=t;
        ans+=num;
        cnt++;
        if(cnt==4)
        {
            t+=2;
            cnt=0;
        }
    }
    cout << ans << endl;
}
