#include<bits/stdc++.h>
using namespace std;
long long dp[100][2];

long long rundp(int j)
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=j;i++)
    {
        dp[i][0]=0;
        dp[i][1]=0;
    }
    dp[j][1]=1;
    for(int i=j;i<=50;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-j][0]+dp[i-j][1]+1;
    }
    return dp[50][0]+dp[50][1];
}



int main()
{
    long long ans=0;
    ans+=rundp(2);
    ans+=rundp(3);
    ans+=rundp(4);
    cout << ans << endl;
}
