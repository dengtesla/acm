#include<bits/stdc++.h>
using namespace std;
//thanks to ljw

int main()
{
    int res=0;
    int ans=0;
    for(int a=12;a<=1000;a+=2)
    {
        int cnt = 0;
        for(int i=3;i<=a/3;i++)
        {
            for(int j=max(i,a/2-i);j<=(a-i)/2;j++)
            {
                if(i*i+j*j==(a-i-j)*(a-i-j)) cnt++;
            }
        }
        if(cnt>=res)
        {
            res = cnt;
            ans = a;
        }
    }
    //cout << res << endl;
    cout << ans << endl;
}
