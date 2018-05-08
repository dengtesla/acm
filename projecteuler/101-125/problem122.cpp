#include<bits/stdc++.h>
using namespace std;
int dp[200];

int main()
{
    memset(dp,0x1f1f1f,sizeof(dp));
    dp[1]=0;
    dp[2]=1;
    int n = 200;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            dp[i]=min(dp[i],max(dp[i-j],dp[j]));
        }
        dp[i]+=1;
    }
    int a;
    while(cin >> a)
    cout << dp[a] << endl;
}
