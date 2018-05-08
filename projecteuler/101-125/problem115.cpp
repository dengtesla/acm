#include<bits/stdc++.h>
using namespace std;
long long dp[700000][3];

int main()
{
    int m,n;
    m=50;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=1;
        dp[i][1]=0;
    }
    dp[m][1]=1;
    n = m+1;
    while(dp[n-1][1]+dp[n-1][0]<=1000000)
    {
        dp[n][1]=dp[n-1][1]+dp[n-m][0];
        dp[n][0]=dp[n-1][1]+dp[n-1][0];
        n++;
    }
    cout << n-1 << endl;
}
